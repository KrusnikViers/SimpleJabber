#include "ui/dialog_page_widget.h"


namespace ui {

DialogPageWidget::DialogPageWidget(QWidget *parent, core::Client& client) :
    QWidget(parent),
    client_(client)
{
    ui_.setupUi(this);
}

void DialogPageWidget::reset()
{
}

}  // namespace ui
