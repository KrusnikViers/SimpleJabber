#pragma once

#include "base/connection_state.h"
#include "ui_connection_state_widget.h"


namespace ui {

class ConnectionStateWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ConnectionStateWidget(QWidget *parent = 0);

public slots:
    void onConnectionStateChanged(base::ConnectionState state);

private:
    Ui::ConnectionStateWidget _ui;

};  // ConnectionStateWidget

}  // namespace ui
