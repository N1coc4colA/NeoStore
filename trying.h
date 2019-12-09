#ifndef TRYING_H
#define TRYING_H

#include <QWidget>

namespace Ui {
class Trying;
}

class Trying : public QWidget
{
    Q_OBJECT

public:
    explicit Trying(QWidget *parent = nullptr);
    ~Trying();

private:
    Ui::Trying *ui;
};

#endif // TRYING_H
