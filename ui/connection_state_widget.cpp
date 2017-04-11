#include "connection_state_widget.h"


namespace ui {

ConnectionStateWidget::ConnectionStateWidget(QWidget *parent) :
    QWidget(parent)
{
    ui_.setupUi(this);
}


void ConnectionStateWidget::onConnectionStateChanged(base::ConnectionState state)
{

}

}  // namespace ui
