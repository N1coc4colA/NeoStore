#include "categoryitem.h"

#include <QSpacerItem>
#include <QHBoxLayout>
#include <QLabel>

CategoryItem::CategoryItem(QPixmap *format, QString *value1, QString *value2, QWidget *parent) : QWidget(parent)
{
    QLabel *icon = new QLabel;
    QLabel *title = new QLabel;
    number = new QLabel;
    QSpacerItem *spacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
    QHBoxLayout *layout = new QHBoxLayout;

    icon->setPixmap(*format);
    title->setText(*value1);

    if (value2 != QString("") && value2 != QString("0")) {
        number->setText(*value2);
        number->setStyleSheet("color: #9c9c9c; background: #fff; border-radius: 10px;");
    } else {
        number->setText("");
        number->setStyleSheet("color: #00000000; background: #00000000; border-radius: 0px;");
    }

    title->setStyleSheet("color: #fff; background: #00000000;");

    layout->addWidget(icon);
    layout->addWidget(title);
    layout->addItem(spacer);
    layout->addWidget(number);

    this->setLayout(layout);
}

void CategoryItem::setValue(int value)
{
    if (value > 0) {
        number->setText(QString::number(value));
        number->setStyleSheet("color: #9c9c9c; background: #fff; border-radius: 10px;");
    } else {
        number->setText("");
        number->setStyleSheet("color: #00000000; background: #00000000; border-radius: 0px;");
    }
}
