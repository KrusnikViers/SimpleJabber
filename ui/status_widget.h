#pragma once

#include "ui_status_widget.h"


namespace ui {

class MainWindow;

class StatusWidget : public QWidget
{
    Q_OBJECT
public:
    // Ordered in priority order: new state can replace current one, if new state is ordered higher.
    // Only exception is None (empty) state - it can replace any other.
    enum State {
        Blocker,
        Process,
        Notification,
        None,
    };

    StatusWidget(MainWindow *parent);

    void reset();

public slots:
    void setState(State state, const QString& text);
    void clearState();

signals:
    void abortRequiested();

private slots:
    void onAbortClicked();
    void onHideClicked();

private:
    Ui::ConnectionStateWidget ui_;

    State state_;

    MainWindow* main_window_;  // Weak.
};  // StatusWidget

}  // namespace ui
