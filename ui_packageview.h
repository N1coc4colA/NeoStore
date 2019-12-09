/********************************************************************************
** Form generated from reading UI file 'packageview.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PACKAGEVIEW_H
#define UI_PACKAGEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PackageData
{
public:
    QHBoxLayout *GlobaL1;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_7;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_7;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget_7;
    QVBoxLayout *verticalLayout_5;
    QLabel *ActionTitle;
    QLabel *UpdateLabel;
    QSpacerItem *verticalSpacer;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_2;
    QPushButton *ActionBtn;
    QPushButton *UpdateBtn;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_4;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *AppName;
    QLabel *AppSection;
    QLabel *AppMaintain;
    QLabel *AppDesc;
    QLabel *label_6;
    QLabel *AppVer;
    QSpacerItem *horizontalSpacer_5;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *closeBtn;
    QWidget *widget_8;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *PackageData)
    {
        if (PackageData->objectName().isEmpty())
            PackageData->setObjectName(QStringLiteral("PackageData"));
        PackageData->resize(707, 497);
        PackageData->setStyleSheet(QStringLiteral("background-color: white;"));
        GlobaL1 = new QHBoxLayout(PackageData);
        GlobaL1->setSpacing(0);
        GlobaL1->setObjectName(QStringLiteral("GlobaL1"));
        GlobaL1->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, -1, -1, 0);
        widget = new QWidget(PackageData);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 130));
        widget->setMaximumSize(QSize(16777215, 300));
        widget->setStyleSheet(QStringLiteral("background-color: white;"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        widget_5 = new QWidget(widget);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setMinimumSize(QSize(250, 200));
        widget_5->setMaximumSize(QSize(200, 250));
        horizontalLayout_4 = new QHBoxLayout(widget_5);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(-1, -1, -1, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, -1, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(-1, -1, -1, 10);
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_4);

        label_7 = new QLabel(widget_5);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(100, 100));
        label_7->setMaximumSize(QSize(100, 100));
        label_7->setStyleSheet(QStringLiteral("border-radius: 5px;"));

        verticalLayout_7->addWidget(label_7);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_3);


        horizontalLayout_2->addLayout(verticalLayout_7);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout_4->addLayout(horizontalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        widget_7 = new QWidget(widget_5);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        widget_7->setMaximumSize(QSize(100, 16777215));
        verticalLayout_5 = new QVBoxLayout(widget_7);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        ActionTitle = new QLabel(widget_7);
        ActionTitle->setObjectName(QStringLiteral("ActionTitle"));
        ActionTitle->setMinimumSize(QSize(0, 25));
        ActionTitle->setMaximumSize(QSize(16777215, 25));

        verticalLayout_5->addWidget(ActionTitle);

        UpdateLabel = new QLabel(widget_7);
        UpdateLabel->setObjectName(QStringLiteral("UpdateLabel"));
        UpdateLabel->setMinimumSize(QSize(0, 25));
        UpdateLabel->setMaximumSize(QSize(16777215, 25));

        verticalLayout_5->addWidget(UpdateLabel);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);


        horizontalLayout_3->addWidget(widget_7);

        widget_6 = new QWidget(widget_5);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        verticalLayout_2 = new QVBoxLayout(widget_6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 0, -1, -1);
        ActionBtn = new QPushButton(widget_6);
        ActionBtn->setObjectName(QStringLiteral("ActionBtn"));

        verticalLayout_2->addWidget(ActionBtn);

        UpdateBtn = new QPushButton(widget_6);
        UpdateBtn->setObjectName(QStringLiteral("UpdateBtn"));

        verticalLayout_2->addWidget(UpdateBtn);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        horizontalLayout_3->addWidget(widget_6);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout_3->addLayout(horizontalLayout_3);


        verticalLayout_4->addLayout(verticalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout_4);


        horizontalLayout->addWidget(widget_5);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        AppName = new QLabel(widget);
        AppName->setObjectName(QStringLiteral("AppName"));

        formLayout->setWidget(0, QFormLayout::FieldRole, AppName);

        AppSection = new QLabel(widget);
        AppSection->setObjectName(QStringLiteral("AppSection"));

        formLayout->setWidget(2, QFormLayout::FieldRole, AppSection);

        AppMaintain = new QLabel(widget);
        AppMaintain->setObjectName(QStringLiteral("AppMaintain"));

        formLayout->setWidget(3, QFormLayout::FieldRole, AppMaintain);

        AppDesc = new QLabel(widget);
        AppDesc->setObjectName(QStringLiteral("AppDesc"));

        formLayout->setWidget(4, QFormLayout::FieldRole, AppDesc);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_6);

        AppVer = new QLabel(widget);
        AppVer->setObjectName(QStringLiteral("AppVer"));

        formLayout->setWidget(1, QFormLayout::FieldRole, AppVer);


        horizontalLayout->addLayout(formLayout);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(PackageData);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setStyleSheet(QStringLiteral("background-color: rgba(0,0,0,0.25);"));
        horizontalLayout_5 = new QHBoxLayout(widget_2);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(widget_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setStyleSheet(QStringLiteral("color: white; background-color: #00000000;"));
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_5);


        verticalLayout->addWidget(widget_2);

        widget_4 = new QWidget(PackageData);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setMinimumSize(QSize(0, 40));
        widget_4->setMaximumSize(QSize(16777215, 40));
        verticalLayout_6 = new QVBoxLayout(widget_4);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(5, 5, 5, 5);
        closeBtn = new QPushButton(widget_4);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));

        horizontalLayout_6->addWidget(closeBtn);

        widget_8 = new QWidget(widget_4);
        widget_8->setObjectName(QStringLiteral("widget_8"));

        horizontalLayout_6->addWidget(widget_8);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);


        verticalLayout_6->addLayout(horizontalLayout_6);


        verticalLayout->addWidget(widget_4);


        GlobaL1->addLayout(verticalLayout);


        retranslateUi(PackageData);

        QMetaObject::connectSlotsByName(PackageData);
    } // setupUi

    void retranslateUi(QWidget *PackageData)
    {
        PackageData->setWindowTitle(QApplication::translate("PackageData", "Form", Q_NULLPTR));
        label_7->setText(QString());
        ActionTitle->setText(QApplication::translate("PackageData", "Action:", Q_NULLPTR));
        UpdateLabel->setText(QString());
        ActionBtn->setText(QApplication::translate("PackageData", "PushButton", Q_NULLPTR));
        UpdateBtn->setText(QApplication::translate("PackageData", "PushButton", Q_NULLPTR));
        label->setText(QApplication::translate("PackageData", "Name: ", Q_NULLPTR));
        label_2->setText(QApplication::translate("PackageData", "Section: ", Q_NULLPTR));
        label_3->setText(QApplication::translate("PackageData", "Maintainer: ", Q_NULLPTR));
        label_4->setText(QApplication::translate("PackageData", "Description: ", Q_NULLPTR));
        AppName->setText(QApplication::translate("PackageData", "Empty", Q_NULLPTR));
        AppSection->setText(QApplication::translate("PackageData", "Empty", Q_NULLPTR));
        AppMaintain->setText(QApplication::translate("PackageData", "Empty", Q_NULLPTR));
        AppDesc->setText(QApplication::translate("PackageData", "Empty", Q_NULLPTR));
        label_6->setText(QApplication::translate("PackageData", "Version: ", Q_NULLPTR));
        AppVer->setText(QApplication::translate("PackageData", "Empty", Q_NULLPTR));
        label_5->setText(QApplication::translate("PackageData", "The screenshot area is not available yet. \n"
" Maybe in the two next months.", Q_NULLPTR));
        closeBtn->setText(QApplication::translate("PackageData", "Close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PackageData: public Ui_PackageData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PACKAGEVIEW_H
