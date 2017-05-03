#include "settings.h"

#include <cassert>


namespace {

QDir dataDirectory()
{
    QDir data_directory(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation));
    if (!data_directory.exists()) {
        data_directory.mkpath(".");
        assert(data_directory.exists());
    }
    return data_directory;
}

QString settingsFilePath()
{
    return dataDirectory().absoluteFilePath(QStringLiteral("settings.ini"));
}

const QString kLoggingKeyName = "logging_type";
const QString kAuthLoginName = "auth_login";
const QString kAuthPasswordName = "auth_password";
const QString kAuthAutologinName = "auth_autologin";
const QString kAuthSaveLoginName = "auth_save";
const QString kAuthHostName = "auth_host";
const QString kAuthPortName = "auth_port";
const QString kAuthResourceName = "auth_resourse";
const QString kProxyTypeName = "proxy_type";
const QString kProxyHostName = "proxy_host";
const QString kProxyPortName = "proxy_port";
const QString kProxyLoginName = "proxy_login";
const QString kProxyPasswordName = "proxy_password";

}  // namespace


namespace core {

using namespace settings;

Settings::Settings() :
    QObject(nullptr),
    settings_(settingsFilePath(), QSettings::IniFormat, this)
{}

Logging Settings::logging() const
{
    int bare_value = settings_.value(kLoggingKeyName, QVariant(static_cast<int>(Logging::None))).toInt();
    return static_cast<Logging>(bare_value);
}

void Settings::setLogging(Logging value)
{
    settings_.setValue(kLoggingKeyName, QVariant(static_cast<int>(value)));
    emit loggingTypeUpdated(value);
}

QString Settings::logFilePath() const
{
    return dataDirectory().absoluteFilePath(QStringLiteral("sj.log"));
}

Authentication Settings::authentication() const
{
    Authentication result;
    result.login = settings_.value(kAuthLoginName).toString();
    result.password = settings_.value(kAuthPasswordName).toString();
    result.is_autologin_enabled = settings_.value(kAuthAutologinName).toBool();
    result.is_login_stored = settings_.value(kAuthSaveLoginName).toBool();
    result.host = settings_.value(kAuthHostName).toString();
    result.port = settings_.value(kAuthPortName).toUInt();
    result.resource = settings_.value(kAuthResourceName).toString();
    return result;
}

void Settings::setAuthentication(Authentication value)
{
    settings_.setValue(kAuthSaveLoginName, value.is_login_stored);
    if (value.is_login_stored)
        settings_.setValue(kAuthLoginName, value.login);
    else
        settings_.remove(kAuthLoginName);

    settings_.setValue(kAuthAutologinName, value.is_autologin_enabled);
    if (value.is_autologin_enabled)
        settings_.setValue(kAuthPasswordName, value.password);
    else
        settings_.remove(kAuthPasswordName);

    settings_.setValue(kAuthHostName, value.host);
    settings_.setValue(kAuthPortName, value.port);
    settings_.setValue(kAuthResourceName, value.resource);

    emit authenticationUpdated();
}

Proxy Settings::proxy() const
{
    Proxy result;
    result.type = static_cast<QNetworkProxy::ProxyType>(settings_.value(kProxyTypeName),
                                                        QVariant(static_cast<int>(QNetworkProxy::NoProxy)).toInt());
    if (result.type == QNetworkProxy::Socks5Proxy || result.type == QNetworkProxy::HttpProxy) {
        result.host = settings_.value(kProxyHostName).toString();
        result.port = settings_.value(kProxyPortName).toUInt();
        result.login = settings_.value(kProxyLoginName).toString();
        result.password = settings_.value(kProxyPasswordName).toString();
    }
    return result;
}

void Settings::setProxy(Proxy value)
{
    settings_.setValue(kProxyTypeName, static_cast<int>(value.type));
    if (value.type != QNetworkProxy::NoProxy) {
        settings_.setValue(kProxyHostName, value.host);
        settings_.setValue(kProxyPortName, value.port);
        settings_.setValue(kProxyLoginName, value.login);
        settings_.setValue(kProxyPasswordName, value.password);
    } else {
        settings_.remove(kProxyHostName);
        settings_.remove(kProxyPortName);
        settings_.remove(kProxyLoginName);
        settings_.remove(kProxyPasswordName);
    }
    emit proxyUpdated();
}

}  // namespace core
