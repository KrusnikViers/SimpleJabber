#pragma once

#include <memory>

#include <QtCore>

#include "core/settings.h"
#include "third_party/qxmpp/src/client/QXmppClient.h"
#include "third_party/qxmpp/src/base/QXmppLogger.h"


namespace core {

class Logger : public QObject
{
    Q_OBJECT
public:
    Logger(Settings& settings, QXmppClient& qxmpp_client);
    ~Logger();

public slots:
    void updateLoggingType(settings::Logging value);

private:
    std::unique_ptr<QXmppLogger> logger_;
    QXmppClient&                 qxmpp_client_;
};

}  // namespace core
