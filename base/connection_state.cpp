#include "connection_state.h"


namespace base {

ConnectionState fromQXmppState(QXmppClient::State state)
{
    switch(state) {
    case QXmppClient::ConnectedState:
        return ConnectionState::Connected;
    case QXmppClient::ConnectingState:
        return ConnectionState::Connecting;
    default:
        return ConnectionState::Disconnected;
    }
}


QXmppClient::State toQXmppState(ConnectionState state)
{
    switch(state) {
    case ConnectionState::Connected:
        return QXmppClient::ConnectedState;
    case ConnectionState::Connecting:
        return QXmppClient::ConnectingState;
    default:
        return QXmppClient::DisconnectedState;
    }
}

}  // namespace base
