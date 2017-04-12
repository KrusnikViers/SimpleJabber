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
    void connectionError(base::ConnectionError error);

private slots:
    void onQXmppStateUpdate(QXmppClient::State state);
    void onQXmppError(QXmppClient::Error error);

private:
    base::ConnectionState state_;
    base::Status          status_;

    QXmppClient           qxmpp_client_;

};  // class Client

}  // namespace core
