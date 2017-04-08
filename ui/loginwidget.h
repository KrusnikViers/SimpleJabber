#pragma once

#include "ui_loginwidget.h"


class LoginWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LoginWidget(QWidget *parent = 0);

signals:
    void loginRequested(const QString& jig, const QString& password);

private slots:
    void onEnterClicked();
    void onOptionsClicked();
    void onBackClicked();

private:
    Ui::LoginWidget _ui;
};
