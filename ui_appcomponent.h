/********************************************************************************
** Form generated from reading UI file 'appcomponent.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPCOMPONENT_H
#define UI_APPCOMPONENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AppComponent
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *AppName;
    QPushButton *pushButton;

    void setupUi(QWidget *AppComponent)
    {
        if (AppComponent->objectName().isEmpty())
            AppComponent->setObjectName(QStringLiteral("AppComponent"));
        AppComponent->resize(300, 50);
        AppComponent->setMinimumSize(QSize(50, 50));
        AppComponent->setMaximumSize(QSize(300, 50));
        AppComponent->setStyleSheet(QStringLiteral("#QFrame{background-color:#fff; border-radius: 5px;}"));
        horizontalLayout = new QHBoxLayout(AppComponent);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(AppComponent);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(6, 0, 6, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(40, 40));
        label->setMaximumSize(QSize(40, 40));

        horizontalLayout_2->addWidget(label);

        AppName = new QLabel(widget);
        AppName->setObjectName(QStringLiteral("AppName"));
        AppName->setMinimumSize(QSize(50, 0));
        AppName->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_2->addWidget(AppName);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(55, 0));
        pushButton->setMaximumSize(QSize(55, 16777215));

        horizontalLayout_2->addWidget(pushButton);


        horizontalLayout->addWidget(widget);


        retranslateUi(AppComponent);

        QMetaObject::connectSlotsByName(AppComponent);
    } // setupUi

    void retranslateUi(QWidget *AppComponent)
    {
        AppComponent->setWindowTitle(QApplication::translate("AppComponent", "Form", Q_NULLPTR));
        label->setText(QString());
        AppName->setText(QApplication::translate("AppComponent", "TextLabel", Q_NULLPTR));
        pushButton->setText(QApplication::translate("AppComponent", "See", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AppComponent: public Ui_AppComponent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPCOMPONENT_H
