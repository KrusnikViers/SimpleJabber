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

struct Credentials {
    QString login;
    QString password;

    bool operator==(const Credentials& other) const
    {
        return login == other.login && password == other.password;
    }
};

struct Connection {
    Credentials user;
    QString     resource;
    QUrl        server;
    bool        is_login_stored = false;
    bool        is_auto_auth_enabled = false;

    bool operator==(const Connection& other) const
    {
        return user == other.user &&
               resource == other.resource &&
               server == other.server &&
               is_login_stored == other.is_login_stored &&
               is_auto_auth_enabled == other.is_auto_auth_enabled;
    }
};

struct Proxy {
    QNetworkProxy::ProxyType type;
    Credentials              user;
    QUrl                     server;

    bool operator==(const Proxy& other)
    {
        return type == other.type && user == other.user && server == other.server;
    }
};

}  // namespace settings
}  // namespace core
