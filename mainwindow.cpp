#include <stdio.h>
#include <iostream>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "installedappstab.h"

#include "installedappitem.h"

#include "QProcess"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("ChocolaGUI");

    // Setup installed apps
    InstalledAppsTab *installedAppsTab = new InstalledAppsTab(nullptr);
    ui->tabInstalled->layout()->addWidget(installedAppsTab);
    installedAppsTab->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
