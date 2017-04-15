#include "user_types.h"

namespace base {

QXmppPresence::AvailableStatusType toQXmppStatus(UserStatus status) {
    switch (status) {
    case UserStatus::Available:
        return QXmppPresence::Online;
    case UserStatus::AwayFromKeyboard:
        return QXmppPresence::Away;
    case UserStatus::AwayForALongTime:
        return QXmppPresence::XA;
    case UserStatus::DoNotDisturb:
    default:
        return QXmppPresence::DND;
    }
}

UserStatus toUserStatus(QXmppPresence::AvailableStatusType status) {
    switch (status) {
    case QXmppPresence::Online:
    case QXmppPresence::Chat:
        return UserStatus::Available;
    case QXmppPresence::Away:
        return UserStatus::AwayFromKeyboard;
    case QXmppPresence::XA:
        return UserStatus::AwayForALongTime;
    case QXmppPresence::DND:
        return UserStatus::DoNotDisturb;
    default:
        return UserStatus::Unavailable;
    }
}

QXmppPresence::Type toQXmppType(UserStatus status) {
    switch (status) {
    case UserStatus::Available:
    case UserStatus::AwayFromKeyboard:
    case UserStatus::AwayForALongTime:
    case UserStatus::DoNotDisturb:
        return QXmppPresence::Available;
    default:
        return QXmppPresence::Unavailable;
    }
}

UserStatus toUserStatus(QXmppPresence::Type type) {
    switch (type) {
    case QXmppPresence::Available:
    case QXmppPresence::Subscribed:
        return UserStatus::Available;
    default:
        return UserStatus::Unavailable;
    }
}

}  // namespace base
