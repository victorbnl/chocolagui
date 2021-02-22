#include "installedappitem.h"
#include "ui_installedappitem.h"

InstalledAppItem::InstalledAppItem(QWidget *parent,
                                   QString appTitle,
                                   QString appInfos,
                                   QString appDescription) :
    QWidget(parent),
    ui(new Ui::InstalledAppItem)
{
    ui->setupUi(this);
    ui->labelAppTitle->setText(appTitle);
    ui->labelAppInfos->setText(appInfos);
    ui->labelAppDescription->setText(appDescription);
}

InstalledAppItem::~InstalledAppItem()
{
    delete ui;
}
