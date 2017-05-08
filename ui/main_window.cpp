#include "main_window.h"


namespace ui {

MainWindow::MainWindow() : QMainWindow(nullptr)
{
    ui_.setupUi(this);
    setUpUIComponents();

    lock_.reset(new QEventLoopLocker());
}

void MainWindow::closeEvent(QCloseEvent* event) {
    connection_state_widget_.reset();
    login_widget_.reset();
    lock_.reset();
    QMainWindow::closeEvent(event);
}

void MainWindow::setUpUIComponents()
{
    connection_state_widget_.reset(new ui::ConnectionStateWidget(this, client_));
    ui_.main_widget->layout()->addWidget(connection_state_widget_.get());
    connection_state_widget_->reset();

    QStackedWidget* stacked_widget = ui_.main_widget->findChild<QStackedWidget*>("stacked_widget");
    login_widget_.reset(new ui::LoginWidget(this, client_));
    stacked_widget->addWidget(login_widget_.get());
    login_widget_->resetLoginPage();
    login_widget_->resetOptionsPage();
}

}  // namespace ui
