#pragma once

#include "ui_dialog_page_widget.h"


namespace ui {

class MainWindow;

class DialogPageWidget : public QWidget
{
    Q_OBJECT
public:
    DialogPageWidget(MainWindow *parent);

    void reset();

private:
    Ui::DialogPageWidget ui_;
};  // class DialogPageWidget

}  // namespace ui
