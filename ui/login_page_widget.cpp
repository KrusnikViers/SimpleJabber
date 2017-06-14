#include "ui/login_page_widget.h"

#include "core/settings.h"
#include "ui/main_window.h"


namespace ui {

LoginPageWidget::LoginPageWidget(MainWindow *parent, core::Client& client) :
    QWidget(parent),
    main_window_(parent),
    client_(client)
{
    ui_.setupUi(this);

    QObject::connect(ui_.connect_button, SIGNAL(clicked(bool)), SLOT(onConnectClicked()));
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
    client_.settings().setConnection(connection_settings);

    reset();
    main_window_->setStatus(StatusWidget::Process, QStringLiteral("Connecting..."));
    client_.connectToServer();
}

}  // namespace ui
