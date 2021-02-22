#include "installedappstab.h"
#include "ui_installedappstab.h"

#include "QProcess"

#include "installedappitem.h"

InstalledAppsTab::InstalledAppsTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InstalledAppsTab)
{
    ui->setupUi(this);
    ui->verticalLayoutResults->setAlignment(Qt::AlignTop);
    refresh();
}

InstalledAppsTab::~InstalledAppsTab()
{
    delete ui;
}

void InstalledAppsTab::refresh() {
    clearList();
    qDebug("REFRESHING");
    std::string query = ui->lineEditSearchQuery->text().toStdString();
    qDebug(query.c_str());
    QProcess listProcess;
    listProcess.start("choco", {"search", query.c_str(), "--no-color", "--local", "--detailed"});
    listProcess.waitForFinished();
    std::string appLine;
    std::string appTitle;
    std::string appDescription;
    bool lastAppExists = false;
    while (listProcess.canReadLine()) {
        std::string line = listProcess.readLine().toStdString();
        if (!QString(line.c_str()).startsWith("Chocolatey v") && !QString(line.c_str()).endsWith(" packages installed.\r\n")) {
            if (!QString(line.c_str()).startsWith(" ") && QString(line.c_str()).compare(QString("\r\n"))) {
                if (lastAppExists) {
                    InstalledAppItem *widget = new InstalledAppItem(
                                nullptr,
                                QString(appTitle.c_str()),
                                QString(appLine.c_str()),
                                QString(appDescription.c_str())
                                );
                    ui->verticalLayoutResults->addWidget(widget);
                }
                appLine = line.substr(0, line.size()-2);
                lastAppExists = true;
            }
            if (QString(line.c_str()).startsWith(" Title: ")) {
                appTitle = line.substr(line.find(":")+2, line.find("|")-(line.find(":")+2));
            }
            if (QString(line.c_str()).startsWith(" Summary: ")) {
                appDescription = line.substr(line.find(":")+2, line.size()-line.find(":")-3);
            }
        }
    }
}


void InstalledAppsTab::clearList() {
    QLayoutItem *child;
    while ((child = ui->verticalLayoutResults->takeAt(0)) != 0) {
        child->widget()->hide();
        delete child;
    }
}
