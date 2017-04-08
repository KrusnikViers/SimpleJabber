#pragma once

#include <memory>

#include <QMainWindow>

#include "core/client.h"
#include "ui_main_window.h"


namespace ui {
class LoginWidget;
}

namespace ui {

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow();

public slots:
    void onLoginRequested(const QString& jid, const QString& password);

private:
    void setUpUIComponents();

    Ui::MainWindow   _ui;
    core::Client     _client;
    ui::LoginWidget* _login_widget;

};  // class MainWindow

}  // namespace ui
