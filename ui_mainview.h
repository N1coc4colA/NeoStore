/********************************************************************************
** Form generated from reading UI file 'mainview.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINVIEW_H
#define UI_MAINVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainView
{
public:
    QHBoxLayout *mainL;
    QWidget *widget;
    QVBoxLayout *sbL;
    QWidget *Main;
    QVBoxLayout *verticalLayout;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *randomL;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *MainView)
    {
        if (MainView->objectName().isEmpty())
            MainView->setObjectName(QStringLiteral("MainView"));
        MainView->resize(893, 602);
        MainView->setMinimumSize(QSize(800, 600));
        MainView->setStyleSheet(QStringLiteral(""));
        mainL = new QHBoxLayout(MainView);
        mainL->setSpacing(0);
        mainL->setObjectName(QStringLiteral("mainL"));
        mainL->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(MainView);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(300, 0));
        widget->setMaximumSize(QSize(300, 16777215));
        widget->setStyleSheet(QStringLiteral(""));
        sbL = new QVBoxLayout(widget);
        sbL->setSpacing(0);
        sbL->setObjectName(QStringLiteral("sbL"));
        sbL->setContentsMargins(0, 0, 0, 0);

        mainL->addWidget(widget);

        Main = new QWidget(MainView);
        Main->setObjectName(QStringLiteral("Main"));
        Main->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(Main);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        widget_3 = new QWidget(Main);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMaximumSize(QSize(16777215, 40));
        widget_3->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(widget_3);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        randomL = new QVBoxLayout();
        randomL->setSpacing(0);
        randomL->setObjectName(QStringLiteral("randomL"));
        randomL->setSizeConstraint(QLayout::SetDefaultConstraint);

        verticalLayout_2->addLayout(randomL);


        verticalLayout->addWidget(widget_3);

        widget_2 = new QWidget(Main);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(500, 600));
        widget_2->setStyleSheet(QStringLiteral("background: rgb(241, 241, 241);"));
        verticalLayout_3 = new QVBoxLayout(widget_2);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setMaximumSize(QSize(16777215, 16777215));
        widget_4->setStyleSheet(QStringLiteral("background: #f3f3f3;"));
        verticalLayout_4 = new QVBoxLayout(widget_4);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout->addItem(verticalSpacer);


        verticalLayout_4->addLayout(horizontalLayout);


        verticalLayout_3->addWidget(widget_4);


        verticalLayout->addWidget(widget_2);


        mainL->addWidget(Main);


        retranslateUi(MainView);

        QMetaObject::connectSlotsByName(MainView);
    } // setupUi

    void retranslateUi(QWidget *MainView)
    {
        MainView->setWindowTitle(QApplication::translate("MainView", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainView: public Ui_MainView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINVIEW_H
