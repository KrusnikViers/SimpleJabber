#pragma once

#include "third_party/qxmpp/src/client/QXmppClient.h"


namespace base {

enum class ConnectionState {
    Initial,
    Disconnected,
    Connecting,
    Connected
};

ConnectionState fromQXmppState(QXmppClient::State state);
QXmppClient::State toQXmppState(ConnectionState state);

}  // namespace base
