#ifndef COMPONENTS_H
#define COMPONENTS_H

#include "appcomponent.h"

#include <QWidget>

namespace Ui {
class Components;
}

class Components : public QWidget
{
    Q_OBJECT

public:
    explicit Components(QWidget *parent = nullptr);
    ~Components();
    int old_length;
    QString old_sec;

public Q_SLOTS:
    void init(QString*);

private:
    Ui::Components *ui;
    AppComponent *app1;
    AppComponent *app2;
    AppComponent *app3;
    AppComponent *app4;
    AppComponent *app5;
    AppComponent *app6;
    AppComponent *app7;
    AppComponent *app8;
    QVector <AppComponent *> APP;
};

#endif // COMPONENTS_H
