/********************************************************************************
** Form generated from reading UI file 'components.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPONENTS_H
#define UI_COMPONENTS_H

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

class Ui_Components
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *MLL;
    QSpacerItem *verticalSpacer;
    QLabel *label;

    void setupUi(QWidget *Components)
    {
        if (Components->objectName().isEmpty())
            Components->setObjectName(QStringLiteral("Components"));
        Components->resize(872, 532);
        verticalLayout_2 = new QVBoxLayout(Components);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        MLL = new QHBoxLayout();
        MLL->setSpacing(0);
        MLL->setObjectName(QStringLiteral("MLL"));

        verticalLayout_2->addLayout(MLL);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        label = new QLabel(Components);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(16777215, 60));
        QFont font;
        font.setPointSize(7);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);


        retranslateUi(Components);

        QMetaObject::connectSlotsByName(Components);
    } // setupUi

    void retranslateUi(QWidget *Components)
    {
        Components->setWindowTitle(QApplication::translate("Components", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("Components", "This Application is the property of n1coc4cola and its content can be under copyright. \n"
"If something come from you and you want it removed from here:\n"
" github.com/N1coc4colA", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Components: public Ui_Components {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPONENTS_H
