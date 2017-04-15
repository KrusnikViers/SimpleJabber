#pragma once

#include "base/connection_types.h"
#include "ui_connection_state_widget.h"

namespace ui {

class ConnectionStateWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ConnectionStateWidget(QWidget *parent = 0);

public slots:
    void onConnectionStateChanged(base::ConnectionState state);
    void onError(base::ConnectionError error);
    void reset();

private:
    Ui::ConnectionStateWidget ui_;
};  // ConnectionStateWidget

}  // namespace ui
