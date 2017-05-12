#pragma once

#include <QtCore>

#include "core/settings_secure.h"
#include "core/settings_types.h"


namespace core {

class Settings : public QObject
{
    Q_OBJECT
public:
    Settings();

    settings::Logging logging() const { return cached_logging_; }
    void setLogging(settings::Logging value);
    QString logFilePath() const;

    settings::Connection connection() const { return cached_connection_; }
    void setConnection(settings::Connection value);

    settings::Proxy proxy() const { return cached_proxy_; }
    void setProxy(settings::Proxy value);

signals:
    void loggingUpdated();
    void connectionUpdated();
    void proxyUpdated();

private slots:
    void logConfigurationForDevelopment() const;

    void connectionPasswordRead(QKeychain::Job* job);
    void proxyPasswordRead(QKeychain::Job* job);

private:
    settings::Logging    cached_logging_;
    settings::Connection cached_connection_;
    settings::Proxy      cached_proxy_;

    QSettings settings_;
};

}  // namespace core
