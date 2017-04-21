#include "login_widget.h"


namespace ui {

LoginWidget::LoginWidget(QWidget *parent) : QWidget(parent)
{
    ui_.setupUi(this);
    QObject::connect(ui_.enter, SIGNAL(clicked(bool)), SLOT(onEnterClicked()));
    QObject::connect(ui_.options, SIGNAL(clicked(bool)), SLOT(onOptionsClicked()));
    QObject::connect(ui_.back, SIGNAL(clicked(bool)), SLOT(reset()));
}

void LoginWidget::reset()
{
    ui_.stacked_widget->setCurrentWidget(ui_.login_page);
}

void LoginWidget::onEnterClicked()
{
    emit loginRequested(ui_.jid->text(), ui_.password->text());
}

void LoginWidget::onOptionsClicked()
{
    ui_.stacked_widget->setCurrentWidget(ui_.options_page);
}

}  // namespace ui
