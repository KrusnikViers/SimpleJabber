#pragma once

#include "ui_login_page_widget.h"


namespace ui {

class MainWindow;

class LoginPageWidget : public QWidget
{
    Q_OBJECT
public:
    LoginPageWidget(MainWindow *parent);
    ~LoginPageWidget() override;

    void reset();

private slots:
    void onConnectClicked();

private:
    Ui::LoginPageWidget ui_;

    MainWindow* main_window_;  // Weak.
};  // class LoginPageWidget

}  // namespace ui
