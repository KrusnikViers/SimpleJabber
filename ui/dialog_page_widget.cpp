#include "ui/dialog_page_widget.h"

#include "ui/main_window.h"


namespace ui {

DialogPageWidget::DialogPageWidget(MainWindow *parent) :
    QWidget(parent)
{
    ui_.setupUi(this);
    reset();
}

void DialogPageWidget::reset()
{
}

}  // namespace ui
