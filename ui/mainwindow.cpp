#include "mainwindow.h"

#include <cassert>


MainWindow::MainWindow() : QMainWindow(nullptr)
{
    _ui.setupUi(this);
    setUpUIComponents();
}

void MainWindow::setUpUIComponents()
{
    QStackedWidget* widgets_stack =
            _ui.widget->findChild<QStackedWidget*>("stacked_widget");

    _login_widget = dynamic_cast<LoginWidget*>(widgets_stack->widget(0));
    QObject::connect(_login_widget, SIGNAL(loginRequested(QString,QString)), SLOT(onLoginRequested(QString,QString)));
}

void MainWindow::onLoginRequested(const QString &jid, const QString &password)
{
    _client.login(jid, password);
}
