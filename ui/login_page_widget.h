#pragma once

#include "core/client.h"
#include "ui/status_widget.h"
#include "ui_login_page_widget.h"


namespace ui {

class MainWindow;

class LoginPageWidget : public QWidget
{
    Q_OBJECT
public:
    LoginPageWidget(MainWindow *parent, core::Client& client);
    ~LoginPageWidget() override;

public slots:
    void reset();

signals:
    void requestState(StatusWidget::State state, const QString& text);

private slots:
    void onConnectClicked();

private:
    Ui::LoginPageWidget ui_;

    MainWindow* main_window_;
    core::Client& client_;
};  // class LoginPageWidget

}  // namespace ui
