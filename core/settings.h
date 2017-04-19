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

signals:
    void loggingTypeUpdated();

private:
    QSettings settings_;
};

}  // namespace core
