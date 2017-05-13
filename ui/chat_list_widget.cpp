#include "ui/chat_list_widget.h"


namespace ui {

ChatListWidget::ChatListWidget(QWidget *parent, core::Client& client) :
    QWidget(parent),
    client_(client)
{
    ui_.setupUi(this);
}

void ChatListWidget::reset()
{
}

}  // namespace ui
