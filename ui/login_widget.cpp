#include "login_widget.h"

#include "core/settings.h"


namespace ui {

LoginWidget::LoginWidget(QWidget *parent, core::Client& client) :
    QWidget(parent),
    client_(client)
{
    ui_.setupUi(this);
    ui_.stacked_widget->setCurrentWidget(ui_.login_page);

    QObject::connect(ui_.connect_button, SIGNAL(clicked(bool)), SLOT(onLoginClicked()));
    QObject::connect(ui_.options_button, SIGNAL(clicked(bool)), SLOT(onOptionsClicked()));
    QObject::connect(ui_.options_cancel_button, SIGNAL(clicked(bool)), SLOT(onOptionsCancelClicked()));
    QObject::connect(ui_.options_apply_button, SIGNAL(clicked(bool)), SLOT(onOptionsCancelClicked()));
    QObject::connect(ui_.proxy_mode_cbox, SIGNAL(currentIndexChanged(int)), SLOT(onProxyModeChanged()));
}

LoginWidget::~LoginWidget()
{
}

void LoginWidget::resetLoginPage()
{
}

void LoginWidget::resetOptionsPage()
{
}

void LoginWidget::onConnectClicked()
{
}

void LoginWidget::onOptionsClicked()
{
    ui_.stacked_widget->setCurrentWidget(ui_.options_page);
}

void LoginWidget::onOptionsApplyClicked()
{
    ui_.stacked_widget->setCurrentWidget(ui_.login_page);
}

void LoginWidget::onOptionsCancelClicked()
{
    ui_.stacked_widget->setCurrentWidget(ui_.login_page);
}

void LoginWidget::onProxyModeChanged()
{
    const bool enable_proxy_fields = ui_.proxy_mode_cbox->currentIndex();
    ui_.proxy_host_edit->setVisible(enable_proxy_fields);
    ui_.proxy_port_edit->setVisible(enable_proxy_fields);
    ui_.proxy_login_edit->setVisible(enable_proxy_fields);
    ui_.proxy_password_edit->setVisible(enable_proxy_fields);
}

void LoginWidget::onConnectionStateChanged()
{
}

}  // namespace ui
