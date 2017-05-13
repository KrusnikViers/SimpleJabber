#pragma once

#include "core/client.h"
#include "ui_chat_list_widget.h"


namespace ui {

class ChatListWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ChatListWidget(QWidget *parent, core::Client& client);

    void reset();

private:
    Ui::ChatListWidget ui_;

    core::Client& client_;
};  // UserListWidget

}  // namespace ui
