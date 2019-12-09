/********************************************************************************
** Form generated from reading UI file 'lookupobj.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOOKUPOBJ_H
#define UI_LOOKUPOBJ_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LookUpObj
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *Icon;
    QLabel *label;

    void setupUi(QWidget *LookUpObj)
    {
        if (LookUpObj->objectName().isEmpty())
            LookUpObj->setObjectName(QStringLiteral("LookUpObj"));
        LookUpObj->resize(200, 214);
        LookUpObj->setMinimumSize(QSize(200, 0));
        LookUpObj->setMaximumSize(QSize(200, 16777215));
        LookUpObj->setStyleSheet(QStringLiteral("border-radius: 9px;"));
        verticalLayout = new QVBoxLayout(LookUpObj);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(10, 10, 10, 10);
        Icon = new QLabel(LookUpObj);
        Icon->setObjectName(QStringLiteral("Icon"));
        Icon->setMinimumSize(QSize(170, 170));
        Icon->setMaximumSize(QSize(170, 170));
        Icon->setStyleSheet(QStringLiteral("border-radius: 5px;"));

        verticalLayout->addWidget(Icon);

        label = new QLabel(LookUpObj);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(170, 16777215));

        verticalLayout->addWidget(label);


        retranslateUi(LookUpObj);

        QMetaObject::connectSlotsByName(LookUpObj);
    } // setupUi

    void retranslateUi(QWidget *LookUpObj)
    {
        LookUpObj->setWindowTitle(QApplication::translate("LookUpObj", "Form", Q_NULLPTR));
        Icon->setText(QString());
        label->setText(QApplication::translate("LookUpObj", "Application Name", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LookUpObj: public Ui_LookUpObj {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOOKUPOBJ_H
