#pragma once

#include "core/client.h"
#include "ui_chat_widget.h"


namespace ui {

class ChatWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ChatWidget(QWidget *parent, core::Client& client);

    void reset();

private:
    Ui::ChatWidget ui_;

    core::Client& client_;
};  // UserListWidget

}  // namespace ui
