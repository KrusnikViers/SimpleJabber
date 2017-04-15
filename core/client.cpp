#include "client.h"

#include "base/project_info.h"

namespace core {

Client::Client() : QObject(nullptr),
                   state_(base::ConnectionState::Initial),
                   status_(base::UserStatus::Unavailable),
                   qxmpp_client_(this),
                   qxmpp_logger_(new QXmppLogger(this)) {
    qxmpp_client_.setLogger(qxmpp_logger_.get());
    qxmpp_logger_->setLogFilePath(base::dataDirectory().canonicalPath()
                                  + QDir::separator() + base::kLogFileName);
    qDebug() << "Log path: " << base::dataDirectory().canonicalPath()
                                + QDir::separator() + base::kLogFileName;
    setXmppLogging(true);
    setupConnections();
}

void Client::login(const QString &jid, const QString &password) {
    qxmpp_client_.connectToServer(jid, password);
}

void Client::setXmppLogging(bool value) {
    if (!value) {
        qxmpp_logger_->setLoggingType(QXmppLogger::NoLogging);
    } else {
        qxmpp_logger_->setLoggingType(QXmppLogger::FileLogging);
        qxmpp_logger_->setMessageTypes(QXmppLogger::MessageTypes(QXmppLogger::AnyMessage));
    }
}

void Client::onQXmppStateUpdate(QXmppClient::State state) {
    emit stateUpdate(base::toConnectionState(state));
}

void Client::onQXmppError(QXmppClient::Error error) {
}

void Client::setupConnections() {
    QObject::connect(&qxmpp_client_,
                     SIGNAL(stateChanged(QXmppClient::State)),
                     SLOT(onQXmppStateUpdate(QXmppClient::State)));
    QObject::connect(&qxmpp_client_,
                     SIGNAL(error(QXmppClient::Error)),
                     SLOT(onQXmppError(QXmppClient::Error)));
}

}  // namespace core
