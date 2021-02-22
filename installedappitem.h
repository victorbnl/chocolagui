#ifndef INSTALLEDAPPITEM_H
#define INSTALLEDAPPITEM_H

#include <QWidget>
#include <string>

namespace Ui {
class InstalledAppItem;
}

class InstalledAppItem : public QWidget
{
    Q_OBJECT

public:
    explicit InstalledAppItem(QWidget *parent,
                              QString appTitle,
                              QString appInfos,
                              QString appDescription);
    ~InstalledAppItem();

private:
    Ui::InstalledAppItem *ui;
};

#endif // INSTALLEDAPPITEM_H
