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
        return QStringLiteral("Host not found");
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
    switch (error) {
    case QAbstractSocket::HostNotFoundError:
        return ConnectionError::NetworkNotFound;
    case QAbstractSocket::SslHandshakeFailedError:
    case QAbstractSocket::SslInternalError:
    case QAbstractSocket::SslInvalidUserDataError:
        return ConnectionError::NetworkSslFailed;
    case QAbstractSocket::ProxyAuthenticationRequiredError:
    case QAbstractSocket::ProxyConnectionRefusedError:
    case QAbstractSocket::ProxyConnectionClosedError:
    case QAbstractSocket::ProxyConnectionTimeoutError:
    case QAbstractSocket::ProxyNotFoundError:
    case QAbstractSocket::ProxyProtocolError:
        return ConnectionError::NetworkProxyError;
    case QAbstractSocket::ConnectionRefusedError:
    case QAbstractSocket::RemoteHostClosedError:
    case QAbstractSocket::SocketAccessError:
    case QAbstractSocket::SocketResourceError:
    case QAbstractSocket::SocketTimeoutError:
    case QAbstractSocket::DatagramTooLargeError:
    case QAbstractSocket::NetworkError:
    case QAbstractSocket::AddressInUseError:
    case QAbstractSocket::SocketAddressNotAvailableError:
    case QAbstractSocket::UnsupportedSocketOperationError:
    case QAbstractSocket::UnfinishedSocketOperationError:
    case QAbstractSocket::OperationError:
    case QAbstractSocket::TemporaryError:
        return ConnectionError::NetworkError;
    case QAbstractSocket::UnknownSocketError:
    default:
        return ConnectionError::UnknownError;
    }
}

ConnectionError toConnectionError(QXmppStanza::Error::Condition error)
{
    switch (error) {
    case QXmppStanza::Error::BadRequest:
    case QXmppStanza::Error::FeatureNotImplemented:
    case QXmppStanza::Error::Conflict:
    case QXmppStanza::Error::Gone:
    case QXmppStanza::Error::ItemNotFound:
    case QXmppStanza::Error::JidMalformed:
    case QXmppStanza::Error::NotAcceptable:
    case QXmppStanza::Error::UndefinedCondition:
    case QXmppStanza::Error::RecipientUnavailable:
    case QXmppStanza::Error::Redirect:
        return ConnectionError::XmppBadRequest;
    case QXmppStanza::Error::Forbidden:
    case QXmppStanza::Error::NotAllowed:
    case QXmppStanza::Error::NotAuthorized:
    case QXmppStanza::Error::PaymentRequired:
    case QXmppStanza::Error::RegistrationRequired:
    case QXmppStanza::Error::ResourceConstraint:
    case QXmppStanza::Error::SubscriptionRequired:
        return ConnectionError::XmppForbidden;
    case QXmppStanza::Error::InternalServerError:
        return ConnectionError::XmppInternalServerError;
    case QXmppStanza::Error::RemoteServerNotFound:
        return ConnectionError::XmppRemoteServerNotFound;
    case QXmppStanza::Error::RemoteServerTimeout:
        return ConnectionError::XmppRemoteServerTimeout;
    case QXmppStanza::Error::ServiceUnavailable:
        return ConnectionError::XmppServiceUnavailable;
    case QXmppStanza::Error::UnexpectedRequest:
        return ConnectionError::XmppUnexpectedRequest;
    default:
        return ConnectionError::UnknownError;
    }
}

}  // namespace base
