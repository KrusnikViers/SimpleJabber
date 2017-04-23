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
    switch (error) {
    case ConnectionError::NoError:
        return QStringLiteral("No error registered");
    case ConnectionError::KeepAliveError:
        return QStringLiteral("Network timeout");
    case ConnectionError::NetworkNotFound:
        return QStringLiteral("Network connection is not active");
    case ConnectionError::NetworkSslFailed:
        return QStringLiteral("Authentication failed");
    case ConnectionError::NetworkProxyError:
        return QStringLiteral("Proxy connection failed");
    case ConnectionError::NetworkError:
        return QStringLiteral("Network error");
    case ConnectionError::XmppBadRequest:
        return QStringLiteral("Bad XMPP request");
    case ConnectionError::XmppForbidden:
        return QStringLiteral("Access denied");
    case ConnectionError::XmppInternalServerError:
        return QStringLiteral("Server internal error");
    case ConnectionError::XmppRemoteServerNotFound:
        return QStringLiteral("Server not found");
    case ConnectionError::XmppRemoteServerTimeout:
        return QStringLiteral("Server not responding");
    case ConnectionError::XmppServiceUnavailable:
        return QStringLiteral("Service unavailable");
    case ConnectionError::XmppUnexpectedRequest:
        return QStringLiteral("Unexpected XMPP request");
    case ConnectionError::UnknownError:
        return QStringLiteral("Unknown error occured");
    }
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
