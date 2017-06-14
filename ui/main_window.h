#pragma once

#include <memory>

#include <QMainWindow>

#include "core/client.h"
#include "ui/dialog_page_widget.h"
#include "ui/status_widget.h"
#include "ui/login_page_widget.h"
#include "ui/settings_page_widget.h"
#include "ui_main_window.h"


namespace ui {

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow();

    void setUIEnabled(bool value);
    void setStatus(StatusWidget::State state, const QString& text);

private:
    void setUpUIComponents();

    core::Client client_;

    Ui::MainWindow ui_;

    std::unique_ptr<ui::DialogPageWidget> dialog_page_widget_;
    std::unique_ptr<ui::LoginPageWidget> login_page_widget_;
    std::unique_ptr<ui::SettingsPageWidget> settings_page_widget_;
    std::unique_ptr<ui::StatusWidget> status_widget_;

    std::unique_ptr<QEventLoopLocker> lock_;
};  // class MainWindow

}  // namespace ui
