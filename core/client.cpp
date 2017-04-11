#include "client.h"


namespace core {

Client::Client() : QObject(nullptr),
                   state_(base::ConnectionState::Initial),
                   status_(base::Status::Unavailable),
                   qxmpp_client_(this)
{
    QObject::connect(&qxmpp_client_, SIGNAL(stateChanged(QXmppClient::State)), SLOT(onStateUpdate(QXmppClient::State)));
}


void Client::login(const QString &jid, const QString &password)
{
    qxmpp_client_.connectToServer(jid, password);
}


void Client::onQXmppStateUpdate(QXmppClient::State state)
{
}

}  // namespace core
