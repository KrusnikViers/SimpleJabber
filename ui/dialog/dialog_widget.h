#pragma once

#include "core/client.h"
#include "ui_dialog_widget.h"


namespace ui {

class DialogWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DialogWidget(QWidget *parent, core::Client& client);

    void reset();

private:
    Ui::DialogWidget ui_;

    core::Client& client_;
};  // DialogWidget

}  // namespace ui
