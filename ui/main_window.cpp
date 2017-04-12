#include "main_window.h"

#include <cassert>

#include "ui/connection_state_widget.h"
#include "ui/login_widget.h"


namespace ui {

MainWindow::MainWindow() : QMainWindow(nullptr)
{
    ui_.setupUi(this);
    setUpUIComponents();
}


void MainWindow::setUpUIComponents()
{
    QStackedWidget* widgets_stack =
            ui_.widget->findChild<QStackedWidget*>("stacked_widget");

    login_widget_ = dynamic_cast<LoginWidget*>(widgets_stack->widget(0));

    QObject::connect(login_widget_, SIGNAL(loginRequested(QString,QString)), SLOT(onLoginRequested(QString,QString)));

    connection_state_widget_ = ui_.widget->findChild<ConnectionStateWidget*>("connection_state_widget");
    connection_state_widget_->reset();
    QObject::connect(&client_, SIGNAL(stateUpdate(base::ConnectionState)),
                     connection_state_widget_, SLOT(onConnectionStateChanged(base::ConnectionState)));
    QObject::connect(&client_, SIGNAL(connectionError(base::ConnectionError)),
                     connection_state_widget_, SLOT(onConnectionError(base::ConnectionError)));
}


void MainWindow::onLoginRequested(const QString &jid, const QString &password)
{
    client_.login(jid, password);
}

}  // namespace ui
