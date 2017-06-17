#pragma once

#include <memory>

#include <QMainWindow>

#include "core/client.h"
#include "ui/status_widget.h"

#include "ui_main_window.h"


namespace ui {

class DialogPageWidget;
class LoginPageWidget;
class SettingsPageWidget;
class StatusWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow();

    void setUIEnabled(bool value);
    void setStatus(StatusWidget::State state, const QString& text);

    core::Client&   client() { return client_; }
    core::Settings& settings() { return client_.settings(); }

private:
    void setUpUIComponents();

    core::Client client_;

    Ui::MainWindow ui_;

    // UI components. All pointers are weak, owned by QMainWindow and initialised by |setUpUIComponents| function.
    ui::DialogPageWidget*   dialog_page_widget_ = nullptr;
    ui::LoginPageWidget*    login_page_widget_ = nullptr;
    ui::SettingsPageWidget* settings_page_widget_ = nullptr;
    ui::StatusWidget*       status_widget_ = nullptr;
};  // class MainWindow

}  // namespace ui
