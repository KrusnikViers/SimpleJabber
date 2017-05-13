#pragma once

#include "core/client.h"
#include "ui_settings_widget.h"


namespace ui {

class SettingsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SettingsWidget(QWidget *parent, core::Client& client);

    void reset();

private:
    Ui::SettingsWidget ui_;

    core::Client& client_;
};  // SettingsWidget

}  // namespace ui
