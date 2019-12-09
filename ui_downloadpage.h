/********************************************************************************
** Form generated from reading UI file 'downloadpage.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOWNLOADPAGE_H
#define UI_DOWNLOADPAGE_H

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

class Ui_UpdatePage
{
public:
    QHBoxLayout *horizontalLayout_5;
    QWidget *mainUp;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QWidget *TITLE;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QPushButton *pushButton;
    QWidget *willet;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget;
    QSpacerItem *verticalSpacer;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_5;
    QWidget *footer;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_2;
    QHBoxLayout *listLayout;

    void setupUi(QWidget *UpdatePage)
    {
        if (UpdatePage->objectName().isEmpty())
            UpdatePage->setObjectName(QStringLiteral("UpdatePage"));
        UpdatePage->resize(754, 439);
        UpdatePage->setStyleSheet(QStringLiteral("#UpdatePage{border-radius: 5px; background-color: #fff; }"));
        horizontalLayout_5 = new QHBoxLayout(UpdatePage);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        mainUp = new QWidget(UpdatePage);
        mainUp->setObjectName(QStringLiteral("mainUp"));
        verticalLayout_4 = new QVBoxLayout(mainUp);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_4->addItem(horizontalSpacer);

        widget = new QWidget(mainUp);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setStyleSheet(QStringLiteral("background: #f3f3f3;"));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        TITLE = new QWidget(widget);
        TITLE->setObjectName(QStringLiteral("TITLE"));
        TITLE->setStyleSheet(QStringLiteral("background: #fff;"));
        horizontalLayout_2 = new QHBoxLayout(TITLE);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(9, 9, 9, 9);
        label = new QLabel(TITLE);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral(""));
        label->setTextInteractionFlags(Qt::NoTextInteraction);

        horizontalLayout_2->addWidget(label);

        pushButton = new QPushButton(TITLE);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(100, 0));
        pushButton->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout_3->addWidget(TITLE);

        willet = new QWidget(widget);
        willet->setObjectName(QStringLiteral("willet"));
        horizontalLayout = new QHBoxLayout(willet);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        listWidget = new QListWidget(willet);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        horizontalLayout->addWidget(listWidget);

        verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout->addItem(verticalSpacer);


        verticalLayout_3->addWidget(willet);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(0, 0));
        widget_3->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout_4 = new QHBoxLayout(widget_3);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalSpacer_3 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_3);

        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_2);

        verticalSpacer_2 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_2);


        horizontalLayout_4->addLayout(verticalLayout_5);

        verticalSpacer_4 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_4->addItem(verticalSpacer_4);


        verticalLayout_3->addWidget(widget_3);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_5);


        verticalLayout_4->addWidget(widget);

        footer = new QWidget(mainUp);
        footer->setObjectName(QStringLiteral("footer"));
        footer->setStyleSheet(QStringLiteral("background: #fff;"));
        horizontalLayout_3 = new QHBoxLayout(footer);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(5, 5, 5, 5);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        pushButton_2 = new QPushButton(footer);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_3->addWidget(pushButton_2);


        verticalLayout_4->addWidget(footer);


        horizontalLayout_5->addWidget(mainUp);

        listLayout = new QHBoxLayout();
        listLayout->setObjectName(QStringLiteral("listLayout"));

        horizontalLayout_5->addLayout(listLayout);


        retranslateUi(UpdatePage);

        QMetaObject::connectSlotsByName(UpdatePage);
    } // setupUi

    void retranslateUi(QWidget *UpdatePage)
    {
        UpdatePage->setWindowTitle(QApplication::translate("UpdatePage", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("UpdatePage", "Available Updates:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("UpdatePage", "Add to changes", Q_NULLPTR));
        label_2->setText(QApplication::translate("UpdatePage", "Ho, ho! Looks like you're up to date!", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("UpdatePage", "See installed packages >", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UpdatePage: public Ui_UpdatePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOWNLOADPAGE_H
