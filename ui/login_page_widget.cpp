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
    if (!connection_settings.server.isEmpty())
        ui_.server_edit->setText(connection_settings.server.toString());
    ui_.resource_edit->setText(connection_settings.resource);

    bool has_optional_settings = !connection_settings.server.isEmpty() || !connection_settings.resource.isEmpty() ||
                                 connection_settings.on_launch_mode != core::settings::Connection::OnLaunchMode::None;
    ui_.options_box->setVisible(has_optional_settings);
}

void LoginPageWidget::onConnectClicked()
{
    auto connection_settings = client_.settings().connection();
    connection_settings.user.login = ui_.login_edit->text();
    connection_settings.user.password = ui_.password_edit->text();
    connection_settings.on_launch_mode =
            static_cast<core::settings::Connection::OnLaunchMode>(ui_.on_launch_mode_cbox->currentIndex());
    if (!ui_.server_edit->text().isEmpty()) {
        QUrl server_url(ui_.server_edit->text());
        if (server_url.isValid())
            connection_settings.server = server_url;
    }
    connection_settings.resource = ui_.resource_edit->text();
    reset();

    client_.settings().setConnection(connection_settings);
    client_.connectToServer();
}

void LoginPageWidget::onOptionsClicked()
{
    // Switch options group box visibility
    ui_.options_box->setVisible(!ui_.options_box->isVisible());
}

}  // namespace ui
