#ifndef PackageData_H
#define PackageData_H

#include "mainview.h"

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

Q_SIGNALS:
    void closing();

public Q_SLOTS:
    void init(QString *);
    void closingOn();

private:
    Ui::PackageData *ui;
    MainView *PARENT;
};

#endif // PackageData_H
