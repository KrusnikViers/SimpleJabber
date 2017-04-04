#include "dockwidget.h"

#include "base/version.h"

DockWidget::DockWidget(QWidget *parent) : QWidget(parent)
{
    _ui.setupUi(this);
    _ui.title->setText(base::kProjectFullVersion);
}
