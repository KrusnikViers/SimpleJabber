#pragma once

#include "core/client.h"
#include "ui_settings_page_widget.h"


namespace ui {

class SettingsPageWidget : public QWidget
{
    Q_OBJECT
public:
    SettingsPageWidget(QWidget *parent, core::Client& client);

    void reset();

private:
    Ui::SettingsWidget ui_;

    core::Client& client_;
};  // SettingsPageWidget

}  // namespace ui
