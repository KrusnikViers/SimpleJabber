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
    settings_(settingsFilePath(), QSettings::IniFormat, this) {
    assert(settings_.status() == QSettings::NoError);
}

Logging Settings::logging() const
{
    return settings_.value(kLoggingKeyName, QVariant::fromValue(Logging::None)).value<Logging>();
}

void Settings::setLogging(Logging value)
{
    settings_.setValue(kLoggingKeyName, QVariant::fromValue(value));
}

QString Settings::logFilePath() const
{
    return dataDirectory().absoluteFilePath(QStringLiteral("sj.log"));
}

}  // namespace core
