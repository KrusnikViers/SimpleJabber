#include "client.h"

#include "base/project_info.h"


namespace core {

Client::Client() :
    QObject(nullptr),
    settings_(),
    state_(base::ConnectionState::Initial),
    status_(base::UserStatus::Unavailable),
    qxmpp_client_(this),
    logger_(settings_, qxmpp_client_)
{
    QObject::connect(&qxmpp_client_,
                     SIGNAL(stateChanged(QXmppClient::State)),
                     SLOT(onQXmppStateUpdate(QXmppClient::State)));
    QObject::connect(&qxmpp_client_,
                     SIGNAL(error(QXmppClient::Error)),
                     SLOT(onQXmppError(QXmppClient::Error)));
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
    switch (error) {
    case QXmppClient::NoError:
        emit errorOccured(base::ConnectionError::NoError);
        break;
    case QXmppClient::KeepAliveError:
        emit errorOccured(base::ConnectionError::KeepAliveError);
        break;
    case QXmppClient::SocketError:
        emit errorOccured(base::toConnectionError(qxmpp_client_.socketError()));
        break;
    case QXmppClient::XmppStreamError:
        emit errorOccured(base::toConnectionError(qxmpp_client_.xmppStreamError()));
        break;
    }
}

}  // namespace core
