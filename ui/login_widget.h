#pragma once

#include "ui_login_widget.h"

namespace ui {

class LoginWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LoginWidget(QWidget *parent = 0);

public slots:
    void reset();

signals:
    void loginRequested(const QString& jig, const QString& password);

private slots:
    void onEnterClicked();
    void onOptionsClicked();

private:
    Ui::LoginWidget ui_;
};  // class LoginWidget

}  // namespace ui
