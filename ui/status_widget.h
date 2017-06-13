#pragma once

#include "core/client.h"
#include "ui_status_widget.h"


namespace ui {

class StatusWidget : public QWidget
{
    Q_OBJECT
public:
    enum State {
        Blocker,
        Process,
        Notification,
        None
    };

    StatusWidget(QWidget *parent, core::Client& client);

    void reset();

public slots:
    void setState(State state, const QString& status);
    void clearState();

signals:
    void abortRequiested();

private slots:
    void onAbortClicked();
    void onHideClicked();

private:
    Ui::ConnectionStateWidget ui_;

    State state_;

    core::Client& client_;
};  // StatusWidget

}  // namespace ui
