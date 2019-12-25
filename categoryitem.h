#ifndef CATEGORYITEM_H
#define CATEGORYITEM_H

#include <QWidget>
#include <QPixmap>
#include <QLabel>

class CategoryItem : public QWidget
{
    Q_OBJECT
public:
    CategoryItem(QPixmap *format, QString *value1, QString *value2, QWidget *parent = nullptr);
    QLabel *number;

public Q_SLOTS:
    void setValue(int);
};

#endif // CATEGORYITEM_H
