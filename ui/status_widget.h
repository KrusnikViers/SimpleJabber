#pragma once

#include "core/client.h"
#include "ui_status_widget.h"


namespace ui {

class MainWindow;

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

    StatusWidget(MainWindow *parent, core::Client& client);

    void reset();

public slots:
    void setState(State state, const QString& text);
    void clearState();

signals:
    void abortRequiested();
    void setUIEnabled(bool enabled);

private slots:
    void onAbortClicked();
    void onHideClicked();

private:
    Ui::ConnectionStateWidget ui_;

    State state_;

    MainWindow* main_window_;
    core::Client& client_;
};  // StatusWidget

}  // namespace ui
