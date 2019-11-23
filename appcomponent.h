#ifndef APPCOMPONENT_H
#define APPCOMPONENT_H

#include <QWidget>

namespace Ui {
class AppComponent;
}

class AppComponent : public QWidget
{
    Q_OBJECT

public:
    explicit AppComponent(QWidget *parent = nullptr);
    ~AppComponent();
    QString *AppName;

public Q_SLOTS:
    void sendData();
    void init(QString *);

Q_SIGNALS:
    void objectClicked(QString *);

private:
    Ui::AppComponent *ui;
};

#endif // APPCOMPONENT_H
