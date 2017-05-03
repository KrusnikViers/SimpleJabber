#pragma once

#include "core/client.h"
#include "ui_login_widget.h"


namespace ui {

class LoginWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LoginWidget(QWidget *parent, core::Client& client);

    void resetLoginPage();
    void resetOptionsPage();

private slots:
    void onLoginClicked();
    void onOptionsClicked();
    void onApplyClicked();
    void onCancelClicked();
    void onProxyModeChanged();

private:
    Ui::LoginWidget ui_;

    core::Client& client_;
};  // class LoginWidget

}  // namespace ui
