#pragma once

#include <memory>

#include <QObject>

#include "base/connection_types.h"
#include "base/user_types.h"
#include "core/logger.h"
#include "core/settings.h"
#include "third_party/qxmpp/src/client/QXmppClient.h"


namespace core {

class Client : public QObject
{
    Q_OBJECT
public:
    Client();

    void login(const QString& jid, const QString& password);

signals:
    void stateUpdate(base::ConnectionState state);
    void error(base::ConnectionError error);

private slots:
    void onQXmppStateUpdate(QXmppClient::State state);
    void onQXmppError(QXmppClient::Error error);

private:
    Settings settings_;

    base::ConnectionState state_;
    base::UserStatus      status_;

    QXmppClient qxmpp_client_;
    Logger      logger_;
};  // class Client

}  // namespace core
