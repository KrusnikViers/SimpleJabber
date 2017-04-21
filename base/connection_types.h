#pragma once

#include <QtNetwork>

#include "third_party/qxmpp/src/base/QXmppStanza.h"
#include "third_party/qxmpp/src/client/QXmppClient.h"


namespace base {

enum class ConnectionState {
    Initial,
    Connecting,
    Connected,
    Disconnected
};

ConnectionState toConnectionState(QXmppClient::State state);
QXmppClient::State toQXmppState(ConnectionState state);

enum class ConnectionError {
    NoError,
    KeepAliveError,
    NetworkNotFound,
    NetworkSslFailed,
    NetworkProxyError,
    NetworkError,
    XmppBadRequest,
    XmppForbidden,
    XmppInternalServerError,
    XmppRemoteServerNotFound,
    XmppRemoteServerTimeout,
    XmppServiceUnavailable,
    XmppUnexpectedRequest,
    UnknownError
};

QString errorDescription(ConnectionError error);
ConnectionError toConnectionError(QAbstractSocket::SocketError error);
ConnectionError toConnectionError(QXmppStanza::Error::Condition error);

}  // namespace base
