#include "client.h"


namespace core {

Client::Client() : QObject(nullptr), _qxmpp_client(this)
{
    QObject::connect(&_qxmpp_client, SIGNAL(stateChanged(QXmppClient::State)), SLOT(onStateUpdate(QXmppClient::State)));
}


void Client::login(const QString &jid, const QString &password)
{
    _qxmpp_client.connectToServer(jid, password);
}


void Client::onStateUpdate(QXmppClient::State state)
{
    qDebug() << state;
}

}  // namespace core
