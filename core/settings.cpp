#include "settings.h"

#include <QHostInfo>

#include "base/project_info.h"
#include "third_party/qtkeychain/keychain.h"


namespace {

constexpr bool isDebugMode()
{
#ifndef NDEBUG
    return true;
#else
    return false
#endif
}

template<class CustomEnum>
CustomEnum readCustomEnum(const QSettings& settings, const QString& key, CustomEnum default_value) {
    return static_cast<CustomEnum>(settings.value(key, static_cast<int>(default_value)).toInt());
}

const QString kSettingsFileName = "settings.ini";

const QString kLoggingSectionPrefix = "logging";
const QString kConnectionSectionPrefix = "connection";

const QString kLoginName = "login";
const QString kPasswordName = "password";
const QString kResourceName = "resource";
const QString kTypeName = "type";
const QString kUrlName = "url";
const QString kOnLaunchModeName = "on_launch_mode";

}  // namespace


namespace core {

using namespace settings;

Settings::Settings() :
    QObject(nullptr),
    settings_(localDataDir().absoluteFilePath(kSettingsFileName), QSettings::IniFormat, this)
{
    parseSettingsFile();

#ifndef NDEBUG
    qDebug() << "Project:       " << base::kProjectFullName;
    qDebug() << "Version:       " << base::kProjectFullVersion;
    qDebug() << "SSL:           " << (base::sslSupported() ? "Enabled" : "Disabled");
    qDebug() << "SSL ver.:      " << base::sslVersion();
    qDebug() << "Storage:       " << localDataDir().absolutePath();
    qDebug() << "Settings:      " << localDataDir().absoluteFilePath(kSettingsFileName);
    qDebug() << "Keychain ver.: " << QTKEYCHAIN_VERSION;
#endif
}

void Settings::parseSettingsFile()
{
    settings_.beginGroup(kLoggingSectionPrefix);
    cached_logging_ = readCustomEnum(settings_, kTypeName, (isDebugMode() ? Logging::Stdout : Logging::None));
    settings_.endGroup();

    settings_.beginGroup(kConnectionSectionPrefix);
    cached_connection_.on_launch_mode =
            readCustomEnum(settings_, kOnLaunchModeName, Connection::OnLaunchMode::None);
    if (cached_connection_.on_launch_mode != Connection::OnLaunchMode::None) {
        cached_connection_.user.login = settings_.value(kLoginName).toString();
        if (cached_connection_.on_launch_mode == Connection::OnLaunchMode::AutoLogin) {
            // Delete itself after finished.
            secure::ReadJob* job = new secure::ReadJob(this);
            job->setKey(kConnectionSectionPrefix + kPasswordName);
            job->setSettings(&settings_);
            QObject::connect(job, SIGNAL(finished(QKeychain::Job*)), SLOT(connectionPasswordRead(QKeychain::Job*)));
            job->start();
        }
    }
    cached_connection_.server = settings_.value(kUrlName).toUrl();
    cached_connection_.resource = settings_.value(kResourceName).toString();
    settings_.endGroup();
}

QDir Settings::localDataDir()
{
    if (isDebugMode())
        return QDir::current();
    QDir data_directory(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation));
    if (!data_directory.exists())
        data_directory.mkpath(".");
    return data_directory;
}

void Settings::setLogging(Logging value)
{
    if (cached_logging_ == value)
        return;
    cached_logging_ = value;
    settings_.beginGroup(kLoggingSectionPrefix);
    settings_.setValue(kTypeName, static_cast<int>(value));
    settings_.endGroup();
    emit loggingUpdated();
}

void Settings::setConnection(Connection value)
{
    if (cached_connection_ == value)
        return;
    cached_connection_ = value;
    settings_.beginGroup(kConnectionSectionPrefix);
    settings_.remove("");
    settings_.setValue(kOnLaunchModeName, static_cast<int>(value.on_launch_mode));
    if (value.on_launch_mode == Connection::OnLaunchMode::StoreLogin)
        settings_.setValue(kLoginName, value.user.login);
    // Delete itself after finished.
    secure::WriteJob* job = new secure::WriteJob(this);
    job->setKey(kConnectionSectionPrefix + kPasswordName);
    job->setTextData(value.on_launch_mode == Connection::OnLaunchMode::AutoLogin ? value.user.password : "");
    job->setSettings(&settings_);
    job->start();
    settings_.setValue(kUrlName, value.server);
    settings_.setValue(kResourceName, value.resource);
    settings_.endGroup();
    emit connectionUpdated();
}

void Settings::connectionPasswordRead(QKeychain::Job* job)
{
    secure::ReadJob* secure_job = dynamic_cast<secure::ReadJob*>(job);
    if (secure_job->textData() != cached_connection_.user.password) {
        cached_connection_.user.password = secure_job->textData();
        emit userPasswordReceived();
        emit connectionUpdated();
    }
}

}  // namespace core
