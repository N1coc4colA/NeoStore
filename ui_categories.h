/********************************************************************************
** Form generated from reading UI file 'categories.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CATEGORIES_H
#define UI_CATEGORIES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Categories
{
public:
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget;

    void setupUi(QWidget *Categories)
    {
        if (Categories->objectName().isEmpty())
            Categories->setObjectName(QStringLiteral("Categories"));
        Categories->resize(516, 522);
        horizontalLayout = new QHBoxLayout(Categories);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        listWidget = new QListWidget(Categories);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        horizontalLayout->addWidget(listWidget);


        retranslateUi(Categories);

        QMetaObject::connectSlotsByName(Categories);
    } // setupUi

    void retranslateUi(QWidget *Categories)
    {
        Categories->setWindowTitle(QApplication::translate("Categories", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Categories: public Ui_Categories {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CATEGORIES_H
