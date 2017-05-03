#pragma once

#include <QtCore>
#include <QtNetwork>


namespace core {
namespace settings {

enum class Logging : int {
    File,
    Stdout,
    None
};

struct Authentication {
    QString login;
    QString password;
    bool    is_login_stored;
    bool    is_autologin_enabled;

    // Optional settings.
    QString host;
    quint16 port;
    QString resource;
};

struct Proxy {
    QNetworkProxy::ProxyType type;

    QString host;
    quint16 port;
    QString login;
    QString password;
};

}  // namespace settings
}  // namespace core
