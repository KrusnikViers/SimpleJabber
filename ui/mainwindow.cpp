#include "mainwindow.h"


MainWindow::MainWindow() : QMainWindow(nullptr), _client(this)
{
    _ui.setupUi(this);
    QObject::connect(&_client,
                     SIGNAL(stateChanged(QXmppClient::State)),
                     SLOT(onStateChanged(QXmppClient::State)));
}

void MainWindow::onStateChanged(QXmppClient::State state) {

}
