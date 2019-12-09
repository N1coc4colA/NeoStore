#ifndef SECONDUI_H
#define SECONDUI_H

#include "mainview.h"

#include <QFutureWatcher>
#include <qapt/backend.h>
#include <QListWidget>

namespace Ui {
class SecondUI;
}

class MainView;

class SecondUI : public QListWidget
{
    Q_OBJECT

public:
    explicit SecondUI(MainView *parent);
    ~SecondUI();
    QString *CURRENT;
    QFutureWatcher<QStringList *> m_watcher;
    QStringList *listON;
    QApt::PackageList *availablePackages;

public Q_SLOTS:
    void handleValues(QString *);
    void runFilter(QString *);
    void checkByChar(QString *);

private:
    Ui::SecondUI *ui;
    QList<QString *> old_list;
    QString *old_Filter;
    int old_length;

public:
Q_SIGNALS:
    void packageWasSelected(QString *);
};

#endif // SECONDUI_H
