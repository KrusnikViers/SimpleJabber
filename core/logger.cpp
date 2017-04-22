#include "core/logger.h"


namespace core {

Logger::Logger(Settings& settings, QXmppClient& qxmpp_client) :
    logger_(new QXmppLogger(this)),
    qxmpp_client_(qxmpp_client)
{
    logger_->setLogFilePath(settings.logFilePath());
    qxmpp_client.setLogger(logger_.get());

    settings.setLogging(settings.logging());
    updateLoggingType(settings.logging());
    QObject::connect(&settings,
                     SIGNAL(loggingTypeUpdated(settings::Logging)),
                     SLOT(updateLoggingType(settings::Logging)));
}

Logger::~Logger()
{
    qxmpp_client_.setLogger(nullptr);
}

void Logger::updateLoggingType(settings::Logging value)
{
    switch (value) {
    case settings::Logging::None:
        logger_->setLoggingType(QXmppLogger::NoLogging);
        break;
    case settings::Logging::Stdout:
        logger_->setLoggingType(QXmppLogger::StdoutLogging);
        break;
    case settings::Logging::File:
        logger_->setLoggingType(QXmppLogger::FileLogging);
        break;
    }
}

}  // namespace core
