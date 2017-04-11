#include "login_widget.h"


namespace ui {

LoginWidget::LoginWidget(QWidget *parent) : QWidget(parent)
{
    ui_.setupUi(this);
    QObject::connect(ui_.enter, SIGNAL(clicked(bool)), SLOT(onEnterClicked()));
    QObject::connect(ui_.options, SIGNAL(clicked(bool)), SLOT(onOptionsClicked()));
    QObject::connect(ui_.back, SIGNAL(clicked(bool)), SLOT(onBackClicked()));
}


void LoginWidget::onEnterClicked()
{
    emit loginRequested(ui_.jid->text(), ui_.password->text());
}


void LoginWidget::onOptionsClicked()
{
    ui_.stacked_widget->setCurrentWidget(ui_.options_page);
}


void LoginWidget::onBackClicked()
{
    ui_.stacked_widget->setCurrentWidget(ui_.login_page);
}

}  // namespace ui
