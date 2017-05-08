#include "settings.h"

#include <QHostInfo>


namespace {

QDir dataDirectory()
{
    QDir data_directory(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation));
    if (!data_directory.exists())
        data_directory.mkpath(".");
    return data_directory;
}

QString settingsFilePath()
{
    return dataDirectory().absoluteFilePath(QStringLiteral("settings.ini"));
}

const QString kLoggingPrefix = "logging";
const QString kConnectionPrefix = "connection";
const QString kProxyPrefix = "proxy";

const QString kLoginName = "login";
const QString kPasswordName = "password";
const QString kResourceName = "resource";
const QString kServerUrlName = "server_url";
const QString kLoginStoredName = "store_login";
const QString kAutoAuthEnabledName = "auto_auth";
const QString kTypeName = "type";

}  // namespace


namespace core {

using namespace settings;

Settings::Settings() :
    QObject(nullptr),
    settings_(settingsFilePath(), QSettings::IniFormat, this)
{
    // Read logging settings.
    settings_.beginGroup(kLoggingPrefix);
    if (settings_.contains(kTypeName)) {
        const int type = settings_.value(kTypeName).toInt();
        cached_logging_ = static_cast<Logging>(type);
    } else {
        cached_logging_ = Logging::None;
        settings_.setValue(kTypeName, static_cast<int>(cached_logging_));
    }
    settings_.endGroup();

    // Read connection settings.
    settings_.beginGroup(kConnectionPrefix);
    cached_connection_.is_login_stored = settings_.value(kLoginStoredName).toBool();
    if (cached_connection_.is_login_stored) {
        cached_connection_.user.login = settings_.value(kLoginName).toString();
        cached_connection_.is_auto_auth_enabled = settings_.value(kAutoAuthEnabledName).toBool();
        if (cached_connection_.is_auto_auth_enabled) {
            // Delete itself after finished.
            secure::ReadJob* job = new secure::ReadJob(this);
            job->setKey(kConnectionPrefix + kPasswordName);
            job->setSettings(&settings_);
            QObject::connect(job, SIGNAL(finished(QKeychain::Job*)), SLOT(connectionPasswordRead(QKeychain::Job*)));
            job->start();
        }
    }
    cached_connection_.server = settings_.value(kServerUrlName).toUrl();
    cached_connection_.resource = settings_.value(kResourceName).toString();
    settings_.endGroup();

    // Read proxy settings.
    settings_.beginGroup(kProxyPrefix);
    if (settings_.contains(kTypeName)) {
        const int type = settings_.value(kTypeName).toInt();
        cached_proxy_.type = static_cast<QNetworkProxy::ProxyType>(type);
    } else {
        cached_proxy_.type = QNetworkProxy::NoProxy;
        settings_.setValue(kTypeName, static_cast<int>(cached_proxy_.type));
    }
    if (cached_proxy_.type != QNetworkProxy::NoProxy) {
        cached_proxy_.server = settings_.value(kServerUrlName).toUrl();
        cached_proxy_.user.login = settings_.value(kLoginName).toString();
        // Delete itself after finished.
        secure::ReadJob* job = new secure::ReadJob(this);
        job->setKey(kProxyPrefix + kPasswordName);
        job->setSettings(&settings_);
        QObject::connect(job, SIGNAL(finished(QKeychain::Job*)), SLOT(proxyPasswordRead(QKeychain::Job*)));
        job->start();
    }
    settings_.endGroup();
}

void Settings::setLogging(Logging value)
{
    if (cached_logging_ == value)
        return;
    cached_logging_ = value;
    settings_.beginGroup(kLoggingPrefix);
    settings_.setValue(kTypeName, static_cast<int>(value));
    settings_.endGroup();
    emit loggingUpdated();
}

QString Settings::logFilePath() const
{
    return dataDirectory().absoluteFilePath(QStringLiteral("sj.log"));
}

void Settings::setConnection(Connection value)
{
    if (cached_connection_ == value)
        return;
    cached_connection_ = value;
    settings_.beginGroup(kConnectionPrefix);
    settings_.remove("");
    settings_.setValue(kLoginStoredName, value.is_login_stored);
    if (value.is_login_stored) {
        settings_.setValue(kLoginName, value.user.login);
        settings_.setValue(kAutoAuthEnabledName, value.is_auto_auth_enabled);
        if (value.is_auto_auth_enabled) {
            // Delete itself after finished.
            secure::WriteJob* job = new secure::WriteJob(this);
            job->setKey(kConnectionPrefix + kPasswordName);
            job->setSettings(&settings_);
            job->start();
        }
    }
    settings_.setValue(kServerUrlName, value.server);
    settings_.setValue(kResourceName, value.resource);
    settings_.endGroup();
    emit connectionUpdated();
}

void Settings::setProxy(Proxy value)
{
    if (cached_proxy_ == value)
        return;
    cached_proxy_ = value;
    settings_.beginGroup(kProxyPrefix);
    settings_.remove("");
    settings_.setValue(kTypeName, static_cast<int>(value.type));
    if (value.type != QNetworkProxy::NoProxy) {
        settings_.setValue(kServerUrlName, value.server);
        settings_.setValue(kLoginName, value.user.login);
        // Delete itself after finished.
        secure::WriteJob* job = new secure::WriteJob(this);
        job->setKey(kProxyPrefix + kPasswordName);
        job->setSettings(&settings_);
        job->start();
    }
    settings_.endGroup();
    emit proxyUpdated();
}

void Settings::connectionPasswordRead(QKeychain::Job* job)
{
    secure::ReadJob* secure_job = dynamic_cast<secure::ReadJob*>(job);
    if (secure_job->textData() != cached_connection_.user.password) {
        cached_connection_.user.password = secure_job->textData();
        emit connectionUpdated();
    }
}

void Settings::proxyPasswordRead(QKeychain::Job* job)
{
    secure::ReadJob* secure_job = dynamic_cast<secure::ReadJob*>(job);
    if (secure_job->textData() != cached_proxy_.user.password) {
        cached_proxy_.user.password = secure_job->textData();
        emit proxyUpdated();
    }
}

}  // namespace core
