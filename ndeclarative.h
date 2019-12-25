#ifndef NDECLARATIVE_H
#define NDECLARATIVE_H

#include <QApt/Backend>
#include <ddialog.h>
#include <QObject>
#include <QList>
#include <QWidget>

DWIDGET_USE_NAMESPACE

class NDeclarative : public DDialog
{
    Q_OBJECT
public:
    explicit NDeclarative(QWidget *parent = nullptr);
    int markedPackages;

Q_SIGNALS:
    void sessionAccepted();
    void sessionDown();

public Q_SLOTS:
         // List order to pass (of QApt::Package::State):
        // ToInstall, ToRemove, ToUpgrade, ToReInstall, ToDowngrade
    void setPKGList(QApt::Backend &);
};

#endif // NDECLARATIVE_H
