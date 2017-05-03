#pragma once

#include "base/connection_types.h"
#include "core/client.h"
#include "ui_connection_state_widget.h"


namespace ui {

class ConnectionStateWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ConnectionStateWidget(QWidget *parent, core::Client& client);

    void reset();

public slots:
    void onConnectionStateChanged(base::ConnectionState state);
    void onError(base::ConnectionError error);
    void onHideClicked();

private:
    Ui::ConnectionStateWidget ui_;

    core::Client& client_;
};  // ConnectionStateWidget

}  // namespace ui
