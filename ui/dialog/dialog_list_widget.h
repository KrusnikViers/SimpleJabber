#pragma once

#include "core/client.h"
#include "ui_dialog_list_widget.h"


namespace ui {

class DialogListWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DialogListWidget(QWidget *parent, core::Client& client);

    void reset();

private:
    Ui::DialogListWidget ui_;

    core::Client& client_;
};  // DialogListWidget

}  // namespace ui
