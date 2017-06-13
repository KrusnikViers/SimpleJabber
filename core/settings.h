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

    static QDir localDataDir();

    settings::Logging logging() const { return cached_logging_; }
    void setLogging(settings::Logging value);

    settings::Connection connection() const { return cached_connection_; }
    void setConnection(settings::Connection value);

signals:
    void loggingUpdated();
    void connectionUpdated();
    void userPasswordReceived();

private slots:
    void connectionPasswordRead(QKeychain::Job* job);

private:
    void parseSettingsFile();

    settings::Logging    cached_logging_;
    settings::Connection cached_connection_;

    QSettings settings_;
};

}  // namespace core
