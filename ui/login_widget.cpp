#include "ui/login_widget.h"

#include "core/settings.h"


namespace {

const int kNoProxySelectionIndex = 0;
const int kSocks5SelectionIndex = 1;
const int kHttpSelectionIndex = 2;

}  // namespace


namespace ui {

LoginWidget::LoginWidget(QWidget *parent, core::Client& client) :
    QWidget(parent),
    client_(client)
{
    ui_.setupUi(this);
    ui_.stacked_widget->setCurrentWidget(ui_.login_page);

    QObject::connect(ui_.connect_button, SIGNAL(clicked(bool)), SLOT(onConnectClicked()));
    QObject::connect(ui_.options_button, SIGNAL(clicked(bool)), SLOT(onOptionsClicked()));
    QObject::connect(ui_.options_apply_button, SIGNAL(clicked(bool)), SLOT(onOptionsApplyClicked()));
    QObject::connect(ui_.options_cancel_button, SIGNAL(clicked(bool)), SLOT(onOptionsCancelClicked()));
    QObject::connect(ui_.proxy_mode_cbox, SIGNAL(currentIndexChanged(int)), SLOT(onProxyModeChanged()));

    QObject::connect(&client.settings(), SIGNAL(connectionUpdated()), SLOT(onConnectionSettingsUpdated()));
    QObject::connect(&client.settings(), SIGNAL(proxyUpdated()), SLOT(onProxySettingsUpdated()));
}

LoginWidget::~LoginWidget()
{
    auto connection_settings = client_.settings().connection();
    connection_settings.on_launch_mode =
            static_cast<core::settings::Connection::OnLaunchMode>(ui_.on_launch_mode_cbox->currentIndex());
    client_.settings().setConnection(connection_settings);
}

void LoginWidget::resetLoginPage()
{
    const auto connection_settings = client_.settings().connection();
    ui_.login_edit->setText(connection_settings.user.login);
    ui_.password_edit->setText(connection_settings.user.password);
    ui_.on_launch_mode_cbox->setCurrentIndex(static_cast<int>(connection_settings.on_launch_mode));
}

void LoginWidget::resetOptionsPage()
{
    const auto connection_settings = client_.settings().connection();
    ui_.host_edit->setText(connection_settings.server.host());
    ui_.port_edit->setText(QString::number(connection_settings.server.port()));
    ui_.resource_edit->setText(connection_settings.resource);

    const auto proxy_settings = client_.settings().proxy();
    switch(proxy_settings.type) {
    case QNetworkProxy::Socks5Proxy:
        ui_.proxy_mode_cbox->setCurrentIndex(kSocks5SelectionIndex);
        break;
    case QNetworkProxy::HttpProxy:
        ui_.proxy_mode_cbox->setCurrentIndex(kHttpSelectionIndex);
        break;
    default:
        ui_.proxy_mode_cbox->setCurrentIndex(kNoProxySelectionIndex);
    }
    onProxyModeChanged();
    ui_.proxy_host_edit->setText(proxy_settings.server.host());
    ui_.proxy_port_edit->setText(QString::number(proxy_settings.server.port()));
    ui_.proxy_login_edit->setText(proxy_settings.user.login);
    ui_.proxy_password_edit->setText(proxy_settings.user.password);
}

void LoginWidget::onConnectClicked()
{
}

void LoginWidget::onOptionsClicked()
{
    ui_.stacked_widget->setCurrentWidget(ui_.options_page);
    resetOptionsPage();
}

void LoginWidget::onOptionsApplyClicked()
{
    ui_.stacked_widget->setCurrentWidget(ui_.login_page);

    auto connection_settings = client_.settings().connection();
    connection_settings.server.setHost(ui_.host_edit->text());
    connection_settings.server.setPort(ui_.port_edit->text().toInt());
    connection_settings.resource = ui_.resource_edit->text();
    client_.settings().setConnection(connection_settings);

    auto proxy_settings = client_.settings().proxy();
    switch(ui_.proxy_mode_cbox->currentIndex()) {
    case kSocks5SelectionIndex:
        proxy_settings.type = QNetworkProxy::Socks5Proxy;
        break;
    case kHttpSelectionIndex:
        proxy_settings.type = QNetworkProxy::HttpProxy;
        break;
    default:
        proxy_settings.type = QNetworkProxy::NoProxy;
    }
    if (proxy_settings.type != QNetworkProxy::NoProxy) {
        proxy_settings.server.setHost(ui_.proxy_host_edit->text());
        proxy_settings.server.setPort(ui_.proxy_port_edit->text().toInt());
        proxy_settings.user.login = ui_.proxy_login_edit->text();
        proxy_settings.user.password = ui_.proxy_password_edit->text();
    }
    client_.settings().setProxy(proxy_settings);
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
    // If client successfully connected, current settings from login screen should be applied.
    if (client_.connectionState() == base::ConnectionState::Connected) {
        auto connection_settings = client_.settings().connection();
        connection_settings.on_launch_mode =
                static_cast<core::settings::Connection::OnLaunchMode>(ui_.on_launch_mode_cbox->currentIndex());
        connection_settings.user.login = ui_.login_edit->text();
        connection_settings.user.password = ui_.password_edit->text();
        client_.settings().setConnection(connection_settings);
    }
}

void LoginWidget::onProxySettingsUpdated()
{
    // Password is only settings, that can be updated in background.
    ui_.proxy_password_edit->setText(client_.settings().proxy().user.password);
}

void LoginWidget::onConnectionSettingsUpdated()
{
    // Password is only settings, that can be updated in background.
    ui_.password_edit->setText(client_.settings().connection().user.password);
}

}  // namespace ui
