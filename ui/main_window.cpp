#include "ui/main_window.h"

#include <cassert>

#include "base/project_info.h"
#include "ui/dialog_page_widget.h"
#include "ui/login_page_widget.h"
#include "ui/settings_page_widget.h"


namespace ui {

MainWindow::MainWindow() : QMainWindow(nullptr)
{
    ui_.setupUi(this);

    setWindowTitle(base::kProjectFullName);
    setUpUIComponents();
    ui_.stacked_widget->setCurrentWidget(login_page_widget_);
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
    QVBoxLayout* layout = dynamic_cast<QVBoxLayout*>(ui_.main_widget->layout());
    assert(layout);

    // Status widget.
    assert(!status_widget_);
    status_widget_ = new ui::StatusWidget(this);
    layout->addWidget(status_widget_);

    const QString stacked_widget_name = "stacked_widget";
    QStackedWidget* stacked_widget = ui_.main_widget->findChild<QStackedWidget*>(stacked_widget_name);
    assert(stacked_widget);

    // Login page widget.
    assert(!login_page_widget_);
    login_page_widget_ = new ui::LoginPageWidget(this);
    stacked_widget->addWidget(login_page_widget_);

    // Dialog page widget.
    assert(!dialog_page_widget_);
    dialog_page_widget_ = new ui::DialogPageWidget(this);
    stacked_widget->addWidget(dialog_page_widget_);

    // Settings page widget.
    assert(!settings_page_widget_);
    settings_page_widget_ = new ui::SettingsPageWidget(this);
    stacked_widget->addWidget(settings_page_widget_);
}

}  // namespace ui
