#pragma once

#include "third_party/qxmpp/src/base/QXmppPresence.h"

namespace base {

enum class UserStatus {
    Available,
    DoNotDisturb,
    AwayFromKeyboard,
    AwayForALongTime,
    Unavailable
};

QXmppPresence::AvailableStatusType toQXmppStatus(UserStatus status);
UserStatus toUserStatus(QXmppPresence::AvailableStatusType status);

QXmppPresence::Type toQXmppType(UserStatus status);
UserStatus toUserStatus(QXmppPresence::Type type);

}  // namespace base
