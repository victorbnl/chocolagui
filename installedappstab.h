#ifndef INSTALLEDAPPSTAB_H
#define INSTALLEDAPPSTAB_H

#include <QWidget>

namespace Ui {
class InstalledAppsTab;
}

class InstalledAppsTab : public QWidget
{
    Q_OBJECT

public:
    explicit InstalledAppsTab(QWidget *parent = nullptr);
    ~InstalledAppsTab();

private slots:
    void refresh();

private:
    Ui::InstalledAppsTab *ui;
    void clearList();
};

#endif // INSTALLEDAPPSTAB_H
