#ifndef INSTALLEDPACKAGESVIEW_H
#define INSTALLEDPACKAGESVIEW_H

#include <QApt/Package>
#include <QWidget>

namespace Ui {
    class InstalledPackagesView;
}

class InstalledPackagesView : public QWidget
{
    Q_OBJECT
public:
    explicit InstalledPackagesView(QApt::PackageList *list, QWidget *parent = nullptr);
    Ui::InstalledPackagesView *ui;

Q_SIGNALS:
    void closing();
    void clicker(QString *);
    void itemWasClicked(QString *);

public Q_SLOTS:
};

#endif // INSTALLEDPACKAGESVIEW_H
