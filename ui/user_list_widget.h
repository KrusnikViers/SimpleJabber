#pragma once

#include "core/client.h"
#include "ui_user_list_widget.h"


namespace ui {

class UserListWidget : public QWidget
{
    Q_OBJECT
public:
    explicit UserListWidget(QWidget *parent, core::Client& client);

    void reset();

private:
    Ui::UserListWidget ui_;

    core::Client& client_;
};  // UserListWidget

}  // namespace ui
