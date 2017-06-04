#include "ui/dialog/dialog_widget.h"


namespace ui {

DialogWidget::DialogWidget(QWidget *parent, core::Client& client) :
    QWidget(parent),
    client_(client)
{
    ui_.setupUi(this);
}

void DialogWidget::reset()
{
}

}  // namespace ui
