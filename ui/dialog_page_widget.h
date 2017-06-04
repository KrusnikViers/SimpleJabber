#pragma once

#include "core/client.h"
#include "ui_dialog_page_widget.h"


namespace ui {

class DialogPageWidget : public QWidget
{
    Q_OBJECT
public:
    DialogPageWidget(QWidget *parent, core::Client& client);

    void reset();

private:
    Ui::DialogPageWidget ui_;

    core::Client& client_;
};  // class DialogPageWidget

}  // namespace ui
