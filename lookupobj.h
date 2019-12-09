#ifndef LOOKUPOBJ_H
#define LOOKUPOBJ_H

#include <QWidget>

namespace Ui {
class LookUpObj;
}

class LookUpObj : public QWidget
{
    Q_OBJECT

public:
    explicit LookUpObj(QString *name, QWidget *parent = nullptr);
    ~LookUpObj();
Q_SIGNALS:
    void clicker(QString *);

private:
    Ui::LookUpObj *ui;
};

#endif // LOOKUPOBJ_H
