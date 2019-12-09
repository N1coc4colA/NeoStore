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
    void callUpdatesView();

private:
    Ui::Categories *ui;
};

#endif // CATEGORIES_H
