#include "ui/status_widget.h"

#include "ui/main_window.h"


namespace ui {

StatusWidget::StatusWidget(MainWindow *parent) :
    QWidget(parent),
    main_window_(parent)
{
    ui_.setupUi(this);
    reset();

    QObject::connect(ui_.hide_button, SIGNAL(clicked(bool)), SLOT(onHideClicked()));
    QObject::connect(ui_.abort_button, SIGNAL(clicked(bool)), SLOT(onAbortClicked()));
}

void StatusWidget::reset()
{
    clearState();
}

void StatusWidget::setState(State state, const QString& status)
{
    if (state < state_ || state == None) {
        state_ = state;
        setEnabled(true);
        setVisible(state != None);
        ui_.status_label->setText(status);
        ui_.hide_button->setVisible(state == Notification);
        ui_.abort_button->setVisible(state == Process);
        main_window_->setUIEnabled(state != Process && state != Blocker);
    }
}

void StatusWidget::clearState()
{
    setState(None, QString());
}

void StatusWidget::onAbortClicked()
{
    setEnabled(false);
    emit abortRequiested();
}

void StatusWidget::onHideClicked()
{
    clearState();
}

}  // namespace ui
