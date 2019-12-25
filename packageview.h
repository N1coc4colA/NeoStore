#ifndef PackageData_H
#define PackageData_H

#include "mainview.h"
#include "screenshotwidget.h"

#include <QWidget>
#include <QtCore/QVariantMap>
#include <QApt/Backend>

namespace Ui {
    class PackageData;
}

class MainView;

class PackageData : public QWidget
{
    Q_OBJECT

public:
    explicit PackageData(MainView *parent);
    ~PackageData();
    QApt::Package *m_package;
    QString old_pkg;
    QString tmpName;
    ScreenShotWidget *screenshotWidget;
    void showFL(bool value);
    bool a = false;

Q_SIGNALS:
    void closing();

public Q_SLOTS:
    void init(QString *);
    void load();
    void closingOn();
    void fileOpenedWithPath(QString *);

private:
    Ui::PackageData *ui;
    MainView *PARENT;
    //ScreenShotWidget *screenshotWidget;
};

#endif // PackageData_H
