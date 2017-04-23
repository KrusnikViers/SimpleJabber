#include "login_widget.h"


namespace ui {

LoginWidget::LoginWidget(QWidget *parent, core::Client& client) :
    QWidget(parent),
    client_(client)
{
    ui_.setupUi(this);
    ui_.stacked_widget->setCurrentWidget(ui_.login_page);

    QObject::connect(ui_.enter, SIGNAL(clicked(bool)), SLOT(onEnterClicked()));
    QObject::connect(ui_.options, SIGNAL(clicked(bool)), SLOT(onOptionsClicked()));
    QObject::connect(ui_.back, SIGNAL(clicked(bool)), SLOT(onBackClicked()));
}

void LoginWidget::resetLoginPage() {}

void LoginWidget::resetOptionsPage() {}

void LoginWidget::onBackClicked()
{
    ui_.stacked_widget->setCurrentWidget(ui_.login_page);
}

void LoginWidget::onEnterClicked()
{
    client_.login(ui_.jid->text(), ui_.password->text());
}

void LoginWidget::onOptionsClicked()
{
    ui_.stacked_widget->setCurrentWidget(ui_.options_page);
}

}  // namespace ui
