#include "connection_state_widget.h"


namespace {

const QString kSocketErrorString = "Connection can not be established.";
const QString kKeepAliveErrorString = "Server not responding.";
const QString kStreamErrorString = "Unexpected response from server.";
const QString kConnectingString = "Connecting...";

const int kConnectingHeightPx = 20;
const int kErrorHeightPx = 40;

}  // namespace


namespace ui {

ConnectionStateWidget::ConnectionStateWidget(QWidget *parent) :
    QWidget(parent)
{
    ui_.setupUi(this);

    QObject::connect(ui_.hide_button, SIGNAL(clicked(bool)), SLOT(reset()));
}


void ConnectionStateWidget::onConnectionStateChanged(base::ConnectionState state)
{
    switch (state)
    {
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


void ConnectionStateWidget::onConnectionError(base::ConnectionError error)
{
    switch (error)
    {
    case base::ConnectionError::KeepAliveError:
        ui_.message_label->setText(kKeepAliveErrorString);
        break;
    case base::ConnectionError::SocketError:
        ui_.message_label->setText(kSocketErrorString);
        break;
    case base::ConnectionError::StreamError:
        ui_.message_label->setText(kStreamErrorString);
        break;
    }
    onConnectionStateChanged(base::ConnectionState::Disconnected);
}


void ConnectionStateWidget::reset()
{
    onConnectionStateChanged(base::ConnectionState::Initial);
}

}  // namespace ui
