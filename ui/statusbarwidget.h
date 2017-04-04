#pragma once

#include <QWidget>

#include "ui_statusbarwidget.h"

class StatusBarWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StatusBarWidget(QWidget *parent = 0);

private:
    Ui::StatusBarWidget _ui;
};
