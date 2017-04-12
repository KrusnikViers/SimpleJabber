#pragma once

#include "third_party/qxmpp/src/client/QXmppClient.h"


namespace base {

enum class ConnectionState {
    Initial,
    Connecting,
    Connected,
    Disconnected
};

ConnectionState fromQXmppState(QXmppClient::State state);
QXmppClient::State toQXmppState(ConnectionState state);


enum class ConnectionError {
    NoError,
    SocketError,
    KeepAliveError,
    StreamError
};

ConnectionError fromQXmppError(QXmppClient::Error error);
QXmppClient::Error toQXmppError(ConnectionError error);

}  // namespace base
