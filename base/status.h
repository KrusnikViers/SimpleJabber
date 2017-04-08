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

QXmppPresence::AvailableStatusType ToQXmppStatus(Status status);
Status FromQXmppStatus(QXmppPresence::AvailableStatusType status);

QXmppPresence::Type ToQXmppType(Status status);
Status FromQXmppType(QXmppPresence::Type type);

}  // namespace base
