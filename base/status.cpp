#include "status.h"


namespace base {

QXmppPresence::AvailableStatusType toQXmppStatus(Status status) {
    switch (status)
    {
    case Status::Available:
        return QXmppPresence::Online;
    case Status::AwayFromKeyboard:
        return QXmppPresence::Away;
    case Status::AwayForALongTime:
        return QXmppPresence::XA;
    case Status::DoNotDisturb:
    default:
        return QXmppPresence::DND;
    }
}


Status fromQXmppStatus(QXmppPresence::AvailableStatusType status) {
    switch (status)
    {
    case QXmppPresence::Online:
    case QXmppPresence::Chat:
        return Status::Available;
    case QXmppPresence::Away:
        return Status::AwayFromKeyboard;
    case QXmppPresence::XA:
        return Status::AwayForALongTime;
    case QXmppPresence::DND:
        return Status::DoNotDisturb;
    default:
        return Status::Unavailable;
    }
}


QXmppPresence::Type toQXmppType(Status status) {
    switch (status)
    {
    case Status::Available:
    case Status::AwayFromKeyboard:
    case Status::AwayForALongTime:
    case Status::DoNotDisturb:
        return QXmppPresence::Available;
    default:
        return QXmppPresence::Unavailable;
    }
}


Status fromQXmppType(QXmppPresence::Type type) {
    switch (type)
    {
    case QXmppPresence::Available:
    case QXmppPresence::Subscribed:
        return Status::Available;
    default:
        return Status::Unavailable;
    }
}

}  // namespace base
