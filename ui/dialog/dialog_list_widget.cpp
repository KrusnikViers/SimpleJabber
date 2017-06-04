#include "ui/dialog/dialog_list_widget.h"


namespace ui {

DialogListWidget::DialogListWidget(QWidget *parent, core::Client& client) :
    QWidget(parent),
    client_(client)
{
    ui_.setupUi(this);
}

void DialogListWidget::reset()
{
}

}  // namespace ui
