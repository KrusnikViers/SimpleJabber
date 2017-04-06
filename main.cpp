#include <QtWidgets>

#include "ui/mainwindow.h"


int main(int argc, char* argv[])
{
    QApplication  main_app(argc, argv);
    MainWindow main_window;
    main_window.show();
    return main_app.exec();
}
