#include "ui/mainwindow.h"

#include "base/version.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    _ui.setupUi(this);
    _ui.version->setText(base::kProjectFullVersion);
}
