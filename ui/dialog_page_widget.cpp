#include "ui/dialog_page_widget.h"

#include "ui/main_window.h"


namespace ui {

DialogPageWidget::DialogPageWidget(MainWindow *parent, core::Client& client) :
    QWidget(parent),
    client_(client)
{
    ui_.setupUi(this);
}

void DialogPageWidget::reset()
{
}

}  // namespace ui
