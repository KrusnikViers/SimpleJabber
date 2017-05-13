#pragma once

#include "core/client.h"
#include "ui_header_widget.h"


namespace ui {

class HeaderWidget : public QWidget
{
    Q_OBJECT
public:
    explicit HeaderWidget(QWidget *parent, core::Client& client);

    void reset();

private:
    Ui::HeaderWidget ui_;

    core::Client& client_;
};  // UserListWidget

}  // namespace ui
