#include "connection_state_widget.h"


namespace {

const int kConnectingHeightPx = 20;
const int kErrorHeightPx = 40;

const QString kConnectingString = "Connecting...";

}  // namespace


namespace ui {

ConnectionStateWidget::ConnectionStateWidget(QWidget *parent) : QWidget(parent)
{
    ui_.setupUi(this);
    QObject::connect(ui_.hide_button, SIGNAL(clicked(bool)), SLOT(reset()));
}

void ConnectionStateWidget::onConnectionStateChanged(base::ConnectionState state)
{
    switch (state) {
    case base::ConnectionState::Connecting:
        show();
        ui_.message_label->setText(kConnectingString);
        ui_.hide_button->hide();
        resize(width(), kConnectingHeightPx);
        break;
    case base::ConnectionState::Disconnected:
        show();
        ui_.hide_button->show();
        resize(width(), kErrorHeightPx);
        break;
    default:
        hide();
        ui_.hide_button->hide();
        resize(width(), 0);
    }
}

void ConnectionStateWidget::onError(base::ConnectionError error)
{
    ui_.message_label->setText(base::errorDescription(error));
}

void ConnectionStateWidget::reset()
{
    onConnectionStateChanged(base::ConnectionState::Initial);
}

}  // namespace ui
