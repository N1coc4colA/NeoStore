/********************************************************************************
** Form generated from reading UI file 'bookpage.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKPAGE_H
#define UI_BOOKPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BookPage
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QWidget *bckg;
    QVBoxLayout *verticalLayout_2;
    QLabel *Title;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout;

    void setupUi(QWidget *BookPage)
    {
        if (BookPage->objectName().isEmpty())
            BookPage->setObjectName(QStringLiteral("BookPage"));
        BookPage->resize(700, 600);
        BookPage->setMinimumSize(QSize(500, 600));
        BookPage->setStyleSheet(QStringLiteral("background-color: rgb(241, 241, 241);"));
        verticalLayout = new QVBoxLayout(BookPage);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(BookPage);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        bckg = new QWidget(widget_2);
        bckg->setObjectName(QStringLiteral("bckg"));
        bckg->setMinimumSize(QSize(400, 300));
        bckg->setMaximumSize(QSize(16777215, 300));
        bckg->setStyleSheet(QStringLiteral("background-position: center; background-origin: content;"));
        verticalLayout_2 = new QVBoxLayout(bckg);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        Title = new QLabel(bckg);
        Title->setObjectName(QStringLiteral("Title"));
        Title->setStyleSheet(QStringLiteral("border-image: url(); background-image: url(); background-color: #00000000; color: white; font-size: 70px;"));
        Title->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(Title);


        horizontalLayout_2->addWidget(bckg);


        verticalLayout->addWidget(widget_2);

        horizontalSpacer_3 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_3);

        widget_3 = new QWidget(BookPage);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setStyleSheet(QStringLiteral(""));
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, 5, 5, 5);

        verticalLayout->addWidget(widget_3);


        retranslateUi(BookPage);

        QMetaObject::connectSlotsByName(BookPage);
    } // setupUi

    void retranslateUi(QWidget *BookPage)
    {
        BookPage->setWindowTitle(QApplication::translate("BookPage", "Form", Q_NULLPTR));
        Title->setText(QApplication::translate("BookPage", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BookPage: public Ui_BookPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKPAGE_H
