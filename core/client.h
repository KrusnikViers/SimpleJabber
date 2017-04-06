#pragma once

#include <QObject>

#include "third_party/qxmpp/src/client/QXmppClient.h"


class Client : public QXmppClient
{
    Q_OBJECT
public:
    explicit Client(QObject* parent);
};
