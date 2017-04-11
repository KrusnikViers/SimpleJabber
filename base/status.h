#pragma once

#include "third_party/qxmpp/src/base/QXmppPresence.h"


namespace base {

enum class Status {
    Available,
    DoNotDisturb,
    AwayFromKeyboard,
    AwayForALongTime,
    Unavailable
};

QXmppPresence::AvailableStatusType toQXmppStatus(Status status);
Status fromQXmppStatus(QXmppPresence::AvailableStatusType status);

QXmppPresence::Type toQXmppType(Status status);
Status fromQXmppType(QXmppPresence::Type type);

}  // namespace base
