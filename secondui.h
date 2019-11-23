#ifndef SECONDUI_H
#define SECONDUI_H

#include <QFutureWatcher>
#include <qapt/backend.h>
#include <QListWidget>
#include "mainview.h"

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

public Q_SLOTS:
    void handleValues(QString *);

private:
    Ui::SecondUI *ui;
    MainView *PARENT;

public:
Q_SIGNALS:
    void packageWasSelected(QString *);
};

#endif // SECONDUI_H
