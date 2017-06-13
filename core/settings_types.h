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
    enum class OnLaunchMode {
        None,
        StoreLogin,
        AutoLogin
    };

    Credentials  user;
    QUrl         server;
    QString      resource;
    OnLaunchMode on_launch_mode;

    bool operator==(const Connection& other) const
    {
        return user == other.user &&
               server == other.server &&
               resource == other.resource &&
               on_launch_mode == other.on_launch_mode;
    }
};

}  // namespace settings
}  // namespace core
