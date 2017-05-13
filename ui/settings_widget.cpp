#include "ui/settings_widget.h"


namespace ui {

SettingsWidget::SettingsWidget(QWidget *parent, core::Client& client) :
    QWidget(parent),
    client_(client)
{
    ui_.setupUi(this);
}

void SettingsWidget::reset()
{
}

}  // namespace ui
