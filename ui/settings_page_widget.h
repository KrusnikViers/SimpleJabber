#pragma once

#include "ui_settings_page_widget.h"


namespace ui {

class MainWindow;

class SettingsPageWidget : public QWidget
{
    Q_OBJECT
public:
    SettingsPageWidget(MainWindow *parent);

    void reset();

private:
    Ui::SettingsWidget ui_;
};  // SettingsPageWidget

}  // namespace ui
