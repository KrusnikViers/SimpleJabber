#include "ui/settings_page_widget.h"

#include "ui/main_window.h"


namespace ui {

SettingsPageWidget::SettingsPageWidget(MainWindow *parent, core::Client& client) :
    QWidget(parent),
    client_(client)
{
    ui_.setupUi(this);
}

void SettingsPageWidget::reset()
{
}

}  // namespace ui
