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
}

QString Settings::logFilePath() const
{
    return dataDirectory().absoluteFilePath(QStringLiteral("sj.log"));
}

}  // namespace core
