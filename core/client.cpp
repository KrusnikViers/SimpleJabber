#include "client.h"


namespace core {

Client::Client() : QObject(nullptr),
                   state_(base::ConnectionState::Initial),
                   status_(base::Status::Unavailable),
                   qxmpp_client_(this)
{
    QObject::connect(
        &qxmpp_client_, SIGNAL(stateChanged(QXmppClient::State)), SLOT(onQXmppStateUpdate(QXmppClient::State)));
    QObject::connect(&qxmpp_client_, SIGNAL(error(QXmppClient::Error)), SLOT(onQXmppError(QXmppClient::Error)));
}


void Client::login(const QString &jid, const QString &password)
{
    qxmpp_client_.connectToServer(jid, password);
}


void Client::onQXmppStateUpdate(QXmppClient::State state)
{
    emit stateUpdate(base::fromQXmppState(state));
}


void Client::onQXmppError(QXmppClient::Error error)
{
    emit connectionError(base::fromQXmppError(error));
}

}  // namespace core
