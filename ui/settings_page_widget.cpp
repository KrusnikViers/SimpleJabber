#include "ui/settings_page_widget.h"


namespace ui {

SettingsPageWidget::SettingsPageWidget(QWidget *parent, core::Client& client) :
    QWidget(parent),
    client_(client)
{
    ui_.setupUi(this);
}

void SettingsPageWidget::reset()
{
}

}  // namespace ui
