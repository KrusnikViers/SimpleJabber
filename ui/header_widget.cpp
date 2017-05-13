#include "ui/header_widget.h"


namespace ui {

HeaderWidget::HeaderWidget(QWidget *parent, core::Client& client) :
    QWidget(parent),
    client_(client)
{
    ui_.setupUi(this);
}

void HeaderWidget::reset()
{
}

}  // namespace ui
