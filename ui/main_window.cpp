#include "main_window.h"

#include <cassert>


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
}


void MainWindow::onLoginRequested(const QString &jid, const QString &password)
{
    client_.login(jid, password);
}

}  // namespace ui
