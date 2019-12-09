/********************************************************************************
** Form generated from reading UI file 'start.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_START_H
#define UI_START_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Start
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *Start)
    {
        if (Start->objectName().isEmpty())
            Start->setObjectName(QStringLiteral("Start"));
        Start->resize(465, 434);
        Start->setStyleSheet(QStringLiteral(""));
        horizontalLayout = new QHBoxLayout(Start);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 20, -1, -1);
        widget_2 = new QWidget(Start);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setStyleSheet(QStringLiteral(""));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        widget = new QWidget(widget_2);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(120, 120));
        widget->setMaximumSize(QSize(120, 120));
        widget->setStyleSheet(QStringLiteral("border-image: url(:/mybg.svg) 0 0 0 0 stretch stretch; border-radius: 10px;"));

        horizontalLayout_2->addWidget(widget);


        verticalLayout->addWidget(widget_2);

        label_3 = new QLabel(Start);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font;
        font.setPointSize(54);
        font.setBold(true);
        font.setWeight(75);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_3);

        label = new QLabel(Start);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral(""));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(Start);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(16777215, 40));
        QFont font1;
        font1.setPointSize(8);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(Start);

        QMetaObject::connectSlotsByName(Start);
    } // setupUi

    void retranslateUi(QWidget *Start)
    {
        Start->setWindowTitle(QApplication::translate("Start", "Form", Q_NULLPTR));
        label_3->setText(QApplication::translate("Start", "NeoStore", Q_NULLPTR));
        label->setText(QApplication::translate("Start", "Looks like it's the first time you start the app since you started your computer...\n"
"NeoStore is a little and simple store which present a selection of apps\n"
"in some different categories. The content is updated every months.", Q_NULLPTR));
        label_2->setText(QApplication::translate("Start", "Some content can take some time to be loaded...\n"
"This isn't fatal, you can continue to browse in the store.", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Start: public Ui_Start {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_START_H
