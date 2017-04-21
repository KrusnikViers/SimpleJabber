#include "connection_types.h"


namespace base {

ConnectionState toConnectionState(QXmppClient::State state)
{
    switch (state) {
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
    switch (state) {
    case ConnectionState::Connected:
        return QXmppClient::ConnectedState;
    case ConnectionState::Connecting:
        return QXmppClient::ConnectingState;
    default:
        return QXmppClient::DisconnectedState;
    }
}

QString errorDescription(ConnectionError error)
{
    return "Unknown error";
}

ConnectionError toConnectionError(QAbstractSocket::SocketError error)
{
    return ConnectionError::UnknownError;
}

ConnectionError toConnectionError(QXmppStanza::Error::Condition error)
{
    return ConnectionError::UnknownError;
}

}  // namespace base
