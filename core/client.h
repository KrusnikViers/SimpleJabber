#pragma once

#include <QObject>

#include "third_party/qxmpp/src/client/QXmppClient.h"
#include "base/connection_state.h"
#include "base/status.h"


namespace core {

class Client : public QObject
{
    Q_OBJECT
public:
    Client();

    void login(const QString& jid, const QString& password);

signals:
    void stateUpdate(base::ConnectionState state);

private slots:
    void onQXmppStateUpdate(QXmppClient::State state);

private:
    base::ConnectionState _state;
    base::Status          _status;

    QXmppClient           _qxmpp_client;

};  // class Client

}  // namespace core
