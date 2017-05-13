#include "ui/user_list_widget.h"


namespace ui {

UserListWidget::UserListWidget(QWidget *parent, core::Client& client) :
    QWidget(parent),
    client_(client)
{
    ui_.setupUi(this);
}

void UserListWidget::reset()
{
}

}  // namespace ui
