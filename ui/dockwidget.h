#pragma once

#include <QWidget>

#include "ui_dockwidget.h"

class DockWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DockWidget(QWidget *parent = 0);

private:
    Ui::DockWidget _ui;
};
