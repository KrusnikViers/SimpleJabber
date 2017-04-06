#pragma once

#include <memory>

#include <QMainWindow>

#include "core/client.h"
#include "ui_mainwindow.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow();

public slots:
    void onStateChanged(QXmppClient::State state);

private:
    Client _client;
    Ui::MainWindow _ui;
};
