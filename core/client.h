#pragma once

#include <memory>

#include <QObject>

#include "base/connection_types.h"
#include "base/user_types.h"
#include "third_party/qxmpp/src/client/QXmppClient.h"
#include "third_party/qxmpp/src/base/QXmppLogger.h"

namespace core {

class Client : public QObject
{
    Q_OBJECT
public:
    Client();

    void login(const QString& jid, const QString& password);
    void setXmppLogging(bool value);

signals:
    void stateUpdate(base::ConnectionState state);
    void error(base::ConnectionError error);

private slots:
    void onQXmppStateUpdate(QXmppClient::State state);
    void onQXmppError(QXmppClient::Error error);

private:
    void setupConnections();

    base::ConnectionState state_;
    base::UserStatus      status_;

    QXmppClient qxmpp_client_;

    std::unique_ptr<QXmppLogger> qxmpp_logger_;
};  // class Client

}  // namespace core
