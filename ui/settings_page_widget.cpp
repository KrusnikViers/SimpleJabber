#include "ui/settings_page_widget.h"

#include "ui/main_window.h"


namespace ui {

SettingsPageWidget::SettingsPageWidget(MainWindow *parent) :
    QWidget(parent)
{
    ui_.setupUi(this);
    reset();
}

void SettingsPageWidget::reset()
{
}

}  // namespace ui
