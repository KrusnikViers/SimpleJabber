#include "login_widget.h"


namespace ui {

LoginWidget::LoginWidget(QWidget *parent, core::Client& client) :
    QWidget(parent),
    client_(client)
{
    ui_.setupUi(this);
    ui_.stacked_widget->setCurrentWidget(ui_.login_page);

    QObject::connect(ui_.login_button, SIGNAL(clicked(bool)), SLOT(onLoginClicked()));
    QObject::connect(ui_.options_button, SIGNAL(clicked(bool)), SLOT(onOptionsClicked()));
    QObject::connect(ui_.back_button, SIGNAL(clicked(bool)), SLOT(onCancelClicked()));
    QObject::connect(ui_.apply_button, SIGNAL(clicked(bool)), SLOT(onApplyClicked()));
    QObject::connect(ui_.proxy_mode, SIGNAL(currentIndexChanged(int)), SLOT(onProxyModeChanged()));
}

void LoginWidget::resetLoginPage() {}

void LoginWidget::resetOptionsPage() {}

void LoginWidget::onLoginClicked()
{
    client_.login(ui_.jid_edit->text(), ui_.password_edit->text());
}

void LoginWidget::onOptionsClicked()
{
    ui_.stacked_widget->setCurrentWidget(ui_.options_page);
}

void LoginWidget::onApplyClicked()
{
    ui_.stacked_widget->setCurrentWidget(ui_.login_page);
}

void LoginWidget::onCancelClicked()
{
    ui_.stacked_widget->setCurrentWidget(ui_.login_page);
}

void LoginWidget::onProxyModeChanged()
{
    const bool enable_proxy_fields = ui_.proxy_mode->currentIndex();
    ui_.proxy_host_edit->setVisible(enable_proxy_fields);
    ui_.proxy_port_edit->setVisible(enable_proxy_fields);
    ui_.proxy_username_edit->setVisible(enable_proxy_fields);
    ui_.proxy_password_edit->setVisible(enable_proxy_fields);
}

}  // namespace ui
