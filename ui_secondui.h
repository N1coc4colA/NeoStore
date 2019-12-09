/********************************************************************************
** Form generated from reading UI file 'secondui.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECONDUI_H
#define UI_SECONDUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SecondUI
{
public:
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget;

    void setupUi(QWidget *SecondUI)
    {
        if (SecondUI->objectName().isEmpty())
            SecondUI->setObjectName(QStringLiteral("SecondUI"));
        SecondUI->resize(16777193, 300);
        horizontalLayout = new QHBoxLayout(SecondUI);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        listWidget = new QListWidget(SecondUI);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        horizontalLayout->addWidget(listWidget);


        retranslateUi(SecondUI);

        QMetaObject::connectSlotsByName(SecondUI);
    } // setupUi

    void retranslateUi(QWidget *SecondUI)
    {
        SecondUI->setWindowTitle(QApplication::translate("SecondUI", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SecondUI: public Ui_SecondUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDUI_H
