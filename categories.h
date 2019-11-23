#ifndef CATEGORIES_H
#define CATEGORIES_H

#include <QWidget>

namespace Ui {
class Categories;
}

class Categories : public QWidget
{
    Q_OBJECT

public:
    explicit Categories(QWidget *parent = nullptr);
    ~Categories();

Q_SIGNALS:
    void showCategory(QString *);
    void showLister();

private:
    Ui::Categories *ui;

private Q_SLOTS:
    void sendData(QString *);
};

#endif // CATEGORIES_H
