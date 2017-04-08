#include "login_widget.h"


namespace ui {

LoginWidget::LoginWidget(QWidget *parent) : QWidget(parent)
{
    _ui.setupUi(this);
    QObject::connect(_ui.enter, SIGNAL(clicked(bool)), SLOT(onEnterClicked()));
    QObject::connect(_ui.options, SIGNAL(clicked(bool)), SLOT(onOptionsClicked()));
    QObject::connect(_ui.back, SIGNAL(clicked(bool)), SLOT(onBackClicked()));
}


void LoginWidget::onEnterClicked()
{
    emit loginRequested(_ui.jid->text(), _ui.password->text());
}


void LoginWidget::onOptionsClicked()
{
    _ui.stacked_widget->setCurrentWidget(_ui.options_page);
}


void LoginWidget::onBackClicked()
{
    _ui.stacked_widget->setCurrentWidget(_ui.login_page);
}

}  // namespace ui
