#ifndef DUPLEXWIDGETCONTROLER_H
#define DUPLEXWIDGETCONTROLER_H

#include <QObject>

class DuplexWidgetControler : public QObject
{
    Q_OBJECT
public:
    explicit DuplexWidgetControler(QObject *parent = nullptr);

public Q_SLOTS:
    void HSLastObject(QWidget *);
    void addObject(QWidget *);

private:
    QList<QWidget *> objList;
    QWidget *oldWidget;
};

#endif // DUPLEXWIDGETCONTROLER_H
