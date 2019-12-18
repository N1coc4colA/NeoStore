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
    Ui::Categories *ui;
    int Updates = 0;
    int AllApps = 0;
    int Tools = 0;

public Q_SLOTS:
    void selectItem(int);

Q_SIGNALS:
    void showCategory(QString *);
    void showLister();
    void callUpdatesView();

private:
};

#endif // CATEGORIES_H
