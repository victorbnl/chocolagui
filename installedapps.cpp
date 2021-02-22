#include "installedapps.h"
#include "ui_installedapps.h"

InstalledApps::InstalledApps(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InstalledApps)
{
    ui->setupUi(this);
}

InstalledApps::~InstalledApps()
{
    delete ui;
}
