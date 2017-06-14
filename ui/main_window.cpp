#include "ui/main_window.h"

#include "base/project_info.h"


namespace ui {

MainWindow::MainWindow() : QMainWindow(nullptr)
{
    ui_.setupUi(this);
    setWindowTitle(base::kProjectFullName);
    setUpUIComponents();

    ui_.stacked_widget->setCurrentWidget(login_page_widget_.get());

    lock_.reset(new QEventLoopLocker());
}

void MainWindow::setUIEnabled(bool value)
{
    ui_.stacked_widget->setEnabled(value);
}

void MainWindow::setStatus(StatusWidget::State state, const QString &text)
{
    status_widget_->setState(state, text);
}

void MainWindow::setUpUIComponents()
{
    QStackedWidget* stacked_widget = ui_.main_widget->findChild<QStackedWidget*>("stacked_widget");

    status_widget_.reset(new ui::StatusWidget(this, client_));
    ui_.main_widget->layout()->addWidget(status_widget_.get());
    status_widget_->reset();

    login_page_widget_.reset(new ui::LoginPageWidget(this, client_));
    stacked_widget->addWidget(login_page_widget_.get());
    login_page_widget_->reset();

    dialog_page_widget_.reset(new ui::DialogPageWidget(this, client_));
    stacked_widget->addWidget(dialog_page_widget_.get());
    dialog_page_widget_->reset();

    settings_page_widget_.reset(new ui::SettingsPageWidget(this, client_));
    stacked_widget->addWidget(settings_page_widget_.get());
    settings_page_widget_->reset();
}

}  // namespace ui
