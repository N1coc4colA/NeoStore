/********************************************************************************
** Form generated from reading UI file 'installedpackagesview.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSTALLEDPACKAGESVIEW_H
#define UI_INSTALLEDPACKAGESVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InstalledPackagesView
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QListWidget *listWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *InstalledPackagesView)
    {
        if (InstalledPackagesView->objectName().isEmpty())
            InstalledPackagesView->setObjectName(QStringLiteral("InstalledPackagesView"));
        InstalledPackagesView->resize(613, 575);
        InstalledPackagesView->setStyleSheet(QStringLiteral("background: #fff;"));
        verticalLayout = new QVBoxLayout(InstalledPackagesView);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(InstalledPackagesView);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(widget_2);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(481, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget_2);

        listWidget = new QListWidget(InstalledPackagesView);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setStyleSheet(QStringLiteral("background: #f3f3f3;"));

        verticalLayout->addWidget(listWidget);

        widget = new QWidget(InstalledPackagesView);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, 5, 5, -1);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(widget);


        retranslateUi(InstalledPackagesView);

        QMetaObject::connectSlotsByName(InstalledPackagesView);
    } // setupUi

    void retranslateUi(QWidget *InstalledPackagesView)
    {
        InstalledPackagesView->setWindowTitle(QApplication::translate("InstalledPackagesView", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("InstalledPackagesView", "Installed Packages", Q_NULLPTR));
        pushButton->setText(QApplication::translate("InstalledPackagesView", "Close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class InstalledPackagesView: public Ui_InstalledPackagesView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSTALLEDPACKAGESVIEW_H
