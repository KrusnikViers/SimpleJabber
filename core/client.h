#pragma once

#include <QObject>

#include "third_party/qxmpp/src/client/QXmppClient.h"


namespace core {

class Client : public QObject
{
    Q_OBJECT
public:
    Client();

    void login(const QString& jid, const QString& password);

private slots:
    void onStateUpdate(QXmppClient::State state);

private:
    QXmppClient _qxmpp_client;

};  // class Client

}  // namespace core
