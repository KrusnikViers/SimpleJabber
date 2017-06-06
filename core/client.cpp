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

void Client::connectToServer()
{
    QXmppConfiguration configuration;
    QXmppPresence initial_presence;

    configuration.setAutoAcceptSubscriptions(true);
    configuration.setAutoReconnectionEnabled(false);
    configuration.setJid(settings_.connection().user.login);
    configuration.setPassword(settings_.connection().user.password);
    configuration.setResource(settings_.connection().resource);
    if (!settings_.connection().server.isEmpty()) {
        configuration.setHost(settings_.connection().server.host());
        configuration.setPort(settings_.connection().server.port());
    }

    qxmpp_client_.connectToServer(configuration, initial_presence);
}

void Client::disconnectFromServer()
{
    qxmpp_client_.disconnect();
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
