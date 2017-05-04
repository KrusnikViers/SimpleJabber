#include "login_widget.h"

#include "core/settings.h"


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

LoginWidget::~LoginWidget() {
    if (ui_.stacked_widget->currentWidget() == ui_.login_page &&
        client_.connectionState() == base::ConnectionState::Disconnected) {
        auto auth_settings = client_.settings().authentication();
        auth_settings.is_autologin_enabled = (ui_.autologin_check->checkState() == Qt::Checked);
        auth_settings.is_login_stored = (ui_.remember_login_check->checkState() == Qt::Checked);
        client_.settings().setAuthentication(auth_settings);
    }
}

void LoginWidget::resetLoginPage() {
    auto auth_settings = client_.settings().authentication();
    ui_.jid_edit->setText(auth_settings.login);
    ui_.password_edit->setText(auth_settings.password);
    ui_.autologin_check->setCheckState(auth_settings.is_autologin_enabled ? Qt::Checked : Qt::Unchecked);
    ui_.remember_login_check->setCheckState(auth_settings.is_login_stored ? Qt::Checked : Qt::Unchecked);
}

void LoginWidget::resetOptionsPage() {
    auto auth_settings = client_.settings().authentication();
    ui_.server_host_edit->setText(auth_settings.host);
    ui_.server_port_edit->setText(QString(auth_settings.port));
    ui_.resource_edit->setText(auth_settings.resource);

    auto proxy_settings = client_.settings().proxy();
    if (proxy_settings.type != QNetworkProxy::NoProxy) {
        ui_.proxy_mode->setCurrentIndex(proxy_settings.type == QNetworkProxy::Socks5Proxy ? 1 : 2);
        ui_.proxy_host_edit->setText(proxy_settings.host);
        ui_.proxy_port_edit->setText(QString(proxy_settings.port));
        ui_.proxy_username_edit->setText(proxy_settings.login);
        ui_.proxy_password_edit->setText(proxy_settings.password);
    } else {
        ui_.proxy_mode->setCurrentIndex(0);
        ui_.proxy_host_edit->clear();
        ui_.proxy_port_edit->clear();
        ui_.proxy_username_edit->clear();
        ui_.proxy_password_edit->clear();
    }
}

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

void LoginWidget::onConnectionStateChanged()
{

}

}  // namespace ui
