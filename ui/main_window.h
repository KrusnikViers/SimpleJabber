#pragma once

#include <memory>

#include <QMainWindow>

#include "core/client.h"
#include "ui/chat_widget.h"
#include "ui/connection_state_widget.h"
#include "ui/login_widget.h"
#include "ui/settings_widget.h"
#include "ui_main_window.h"


namespace ui {

class LoginWidget;
class ConnectionStateWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow();

private:
    void setUpUIComponents();

    core::Client client_;

    Ui::MainWindow ui_;

    std::unique_ptr<ui::ChatWidget>            chat_widget_;
    std::unique_ptr<ui::LoginWidget>           login_widget_;
    std::unique_ptr<ui::ConnectionStateWidget> connection_state_widget_;
    std::unique_ptr<ui::SettingsWidget>        settings_widget_;

    std::unique_ptr<QEventLoopLocker> lock_;
};  // class MainWindow

}  // namespace ui
