#pragma once

#include "core/client.h"
#include "ui_login_page_widget.h"


namespace ui {

class LoginPageWidget : public QWidget
{
    Q_OBJECT
public:
    LoginPageWidget(QWidget *parent, core::Client& client);
    ~LoginPageWidget() override;

public slots:
    void reset();

private slots:
    void onConnectClicked();
    void onOptionsClicked();

    void onConnectionStateChanged();
    void onConnectionSettingsUpdated();

private:
    Ui::LoginPageWidget ui_;

    core::Client& client_;
};  // class LoginPageWidget

}  // namespace ui
