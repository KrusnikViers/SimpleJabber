#pragma once

#include <QtCore>

#include "core/settings_types.h"


namespace core {

class Settings : public QObject
{
    Q_OBJECT
public:
    Settings();

    settings::Logging logging() const;
    void setLogging(settings::Logging value);
    QString logFilePath() const;

    settings::Authentication authentication() const;
    void setAuthentication(settings::Authentication value);

    settings::Proxy proxy() const;
    void setProxy(settings::Proxy value);

signals:
    void loggingTypeUpdated(settings::Logging value);
    void authenticationUpdated();
    void proxyUpdated();

private:
    QSettings settings_;
};

}  // namespace core
