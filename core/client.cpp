#include "client.h"

#include <cassert>

#include <QSslSocket>

#include "base/project_info.h"

namespace core {

Client::Client() : QObject(nullptr),
                   state_(base::ConnectionState::Initial),
                   status_(base::UserStatus::Unavailable),
                   qxmpp_client_(this)
{
    // SSL expected to be enabled by default.
    assert(QSslSocket::supportsSsl());
    setupConnections();
}

void Client::login(const QString &jid, const QString &password)
{
    qxmpp_client_.connectToServer(jid, password);
}

void Client::onQXmppStateUpdate(QXmppClient::State state)
{
    emit stateUpdate(base::toConnectionState(state));
}

void Client::onQXmppError(QXmppClient::Error error)
{
}

void Client::setupConnections()
{
    QObject::connect(&qxmpp_client_,
                     SIGNAL(stateChanged(QXmppClient::State)),
                     SLOT(onQXmppStateUpdate(QXmppClient::State)));
    QObject::connect(&qxmpp_client_,
                     SIGNAL(error(QXmppClient::Error)),
                     SLOT(onQXmppError(QXmppClient::Error)));
}

}  // namespace core
