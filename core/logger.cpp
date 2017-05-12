#include "core/logger.h"


namespace core {

Logger::Logger(Settings& settings, QXmppClient& qxmpp_client) :
    settings_(settings),
    qxmpp_client_(qxmpp_client),
    logger_(new QXmppLogger(this))
{
    logger_->setLogFilePath(settings_.logFilePath());
    qxmpp_client.setLogger(logger_.get());

    updateLogging();
    QObject::connect(&settings, SIGNAL(loggingUpdated()), SLOT(updateLogging()));
}

Logger::~Logger()
{
    qxmpp_client_.setLogger(nullptr);
}

void Logger::updateLogging()
{
    switch (settings_.logging()) {
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
