#pragma once

#include <memory>

#include <QMainWindow>

#include "core/client.h"
#include "ui_mainwindow.h"

class LoginWidget;


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow();

public slots:
    void onLoginRequested(const QString& jid, const QString& password);

private:
    void setUpUIComponents();

    Client         _client;
    Ui::MainWindow _ui;
    // Ui components
    LoginWidget* _login_widget;
};
