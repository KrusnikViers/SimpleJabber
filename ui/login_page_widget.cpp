#include "ui/login_page_widget.h"

#include "core/settings.h"


namespace ui {

LoginPageWidget::LoginPageWidget(QWidget *parent, core::Client& client) :
    QWidget(parent),
    client_(client)
{
    ui_.setupUi(this);

    QObject::connect(ui_.connect_button, SIGNAL(clicked(bool)), SLOT(onConnectClicked()));
    QObject::connect(ui_.options_button, SIGNAL(clicked(bool)), SLOT(onOptionsClicked()));

    QObject::connect(&client.settings(), SIGNAL(connectionUpdated()), SLOT(onConnectionSettingsUpdated()));
}

LoginPageWidget::~LoginPageWidget()
{
    // If client is not connected yet, apply selected launch mode before exit
    if (client_.connectionState() != base::ConnectionState::Connected) {
        auto connection_settings = client_.settings().connection();
        connection_settings.on_launch_mode =
                static_cast<core::settings::Connection::OnLaunchMode>(ui_.on_launch_mode_cbox->currentIndex());
        client_.settings().setConnection(connection_settings);
    }
}

void LoginPageWidget::reset()
{
    const auto connection_settings = client_.settings().connection();
    ui_.login_edit->setText(connection_settings.user.login);
    ui_.password_edit->setText(connection_settings.user.password);
    ui_.on_launch_mode_cbox->setCurrentIndex(static_cast<int>(connection_settings.on_launch_mode));
}

void LoginPageWidget::onConnectClicked()
{
    auto connection_settings = client_.settings().connection();
    connection_settings.user.login = ui_.login_edit->text();
    connection_settings.user.password = ui_.password_edit->text();
    connection_settings.on_launch_mode =
            static_cast<core::settings::Connection::OnLaunchMode>(ui_.on_launch_mode_cbox->currentIndex());
    client_.settings().setConnection(connection_settings);
    client_.connectToServer();
}

void LoginPageWidget::onOptionsClicked()
{
}

void LoginPageWidget::onConnectionStateChanged()
{
}

void LoginPageWidget::onConnectionSettingsUpdated()
{
    // Accept new password, if it was updated in background
    const QString new_password = client_.settings().connection().user.password;
    if (!new_password.isEmpty())
        ui_.password_edit->setText(client_.settings().connection().user.password);
}

}  // namespace ui
