#include "ui/chat_widget.h"


namespace ui {

ChatWidget::ChatWidget(QWidget *parent, core::Client& client) :
    QWidget(parent),
    client_(client)
{
    ui_.setupUi(this);
}

void ChatWidget::reset()
{
}

}  // namespace ui
