#include "connection_state.h"


namespace base {

ConnectionState fromQXmppState(QXmppClient::State state)
{
    switch (state)
    {
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
    switch (state)
    {
    case ConnectionState::Connected:
        return QXmppClient::ConnectedState;
    case ConnectionState::Connecting:
        return QXmppClient::ConnectingState;
    default:
        return QXmppClient::DisconnectedState;
    }
}


ConnectionError fromQXmppError(QXmppClient::Error error)
{
    switch (error)
    {
    case QXmppClient::NoError:
        return ConnectionError::NoError;
    case QXmppClient::SocketError:
        return ConnectionError::SocketError;
    case QXmppClient::KeepAliveError:
        return ConnectionError::KeepAliveError;
    case QXmppClient::XmppStreamError:
        return ConnectionError::StreamError;
    }
}


QXmppClient::Error toQXmppError(ConnectionError error)
{
    switch(error)
    {
    case ConnectionError::NoError:
        return QXmppClient::NoError;
    case ConnectionError::SocketError:
        return QXmppClient::SocketError;
    case ConnectionError::KeepAliveError:
        return QXmppClient::KeepAliveError;
    case ConnectionError::StreamError:
        return QXmppClient::XmppStreamError;
    }
}

}  // namespace base
