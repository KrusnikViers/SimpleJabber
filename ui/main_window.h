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

    Ui::MainWindow   ui_;
    core::Client     client_;
    ui::LoginWidget* login_widget_;

};  // class MainWindow

}  // namespace ui
