#include "ui/main_window.h"

#include "base/project_info.h"


namespace ui {

MainWindow::MainWindow() : QMainWindow(nullptr)
{
    ui_.setupUi(this);
    setUpUIComponents();
    ui_.stacked_widget->setCurrentWidget(login_widget_.get());

    setWindowTitle(base::kProjectFullName);

    lock_.reset(new QEventLoopLocker());
}

void MainWindow::setUpUIComponents()
{
    QStackedWidget* stacked_widget = ui_.main_widget->findChild<QStackedWidget*>("stacked_widget");

    connection_state_widget_.reset(new ui::ConnectionStateWidget(this, client_));
    ui_.main_widget->layout()->addWidget(connection_state_widget_.get());
    connection_state_widget_->reset();

    login_widget_.reset(new ui::LoginWidget(this, client_));
    stacked_widget->addWidget(login_widget_.get());
    login_widget_->resetLoginPage();
    login_widget_->resetOptionsPage();

    chat_widget_.reset(new ui::ChatWidget(this, client_));
    stacked_widget->addWidget(chat_widget_.get());
    chat_widget_->reset();

    settings_widget_.reset(new ui::SettingsWidget(this, client_));
    stacked_widget->addWidget(settings_widget_.get());
    settings_widget_->reset();
}

}  // namespace ui
