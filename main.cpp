#include <QtWidgets>

#include "ui/main_window.h"

int main(int argc, char* argv[])
{
    QApplication main_app(argc, argv);
    main_app.setQuitOnLastWindowClosed(true);
    main_app.setQuitLockEnabled(true);

    ui::MainWindow main_window;
    main_window.show();

    return main_app.exec();
}
