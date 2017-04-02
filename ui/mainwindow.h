#pragma once

#include <memory>

#include <QMainWindow>

#include "ui_mainwindow.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    Ui::MainWindow _ui;
};
