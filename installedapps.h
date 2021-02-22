#ifndef INSTALLEDAPPS_H
#define INSTALLEDAPPS_H

#include <QWidget>

namespace Ui {
class InstalledApps;
}

class InstalledApps : public QWidget
{
    Q_OBJECT

public:
    explicit InstalledApps(QWidget *parent = nullptr);
    ~InstalledApps();

private:
    Ui::InstalledApps *ui;
};

#endif // INSTALLEDAPPS_H
