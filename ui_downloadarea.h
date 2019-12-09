/********************************************************************************
** Form generated from reading UI file 'downloadarea.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOWNLOADAREA_H
#define UI_DOWNLOADAREA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DownloadArea
{
public:
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *status;
    QSpacerItem *horizontalSpacer;
    QLabel *dinteger;
    QLabel *label_4;
    QProgressBar *progressBar;
    QPushButton *pushButton;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *DownloadArea)
    {
        if (DownloadArea->objectName().isEmpty())
            DownloadArea->setObjectName(QStringLiteral("DownloadArea"));
        DownloadArea->resize(843, 75);
        DownloadArea->setStyleSheet(QLatin1String("#QWidget {background-color: #0000006b;}\n"
"#DownloadArea {background-color: #0000006b;}"));
        horizontalLayout_2 = new QHBoxLayout(DownloadArea);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(DownloadArea);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setStyleSheet(QStringLiteral("#QWidget {background-color: #0000006b;}"));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        status = new QLabel(widget);
        status->setObjectName(QStringLiteral("status"));

        horizontalLayout->addWidget(status);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        dinteger = new QLabel(widget);
        dinteger->setObjectName(QStringLiteral("dinteger"));

        horizontalLayout->addWidget(dinteger);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout->addWidget(label_4);


        verticalLayout->addLayout(horizontalLayout);

        progressBar = new QProgressBar(widget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        verticalLayout->addWidget(progressBar);


        horizontalLayout_3->addLayout(verticalLayout);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(20, 55));
        pushButton->setMaximumSize(QSize(20, 55));

        horizontalLayout_3->addWidget(pushButton);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setStyleSheet(QStringLiteral("#QWidget {background-color: #00000000;}"));
        horizontalLayout_4 = new QHBoxLayout(widget_2);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_4->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        horizontalLayout_3->addWidget(widget_2);


        horizontalLayout_2->addWidget(widget);


        retranslateUi(DownloadArea);

        QMetaObject::connectSlotsByName(DownloadArea);
    } // setupUi

    void retranslateUi(QWidget *DownloadArea)
    {
        DownloadArea->setWindowTitle(QApplication::translate("DownloadArea", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("DownloadArea", "Status:", Q_NULLPTR));
        status->setText(QApplication::translate("DownloadArea", "Downloading", Q_NULLPTR));
        dinteger->setText(QApplication::translate("DownloadArea", "0", Q_NULLPTR));
        label_4->setText(QApplication::translate("DownloadArea", "Mo/s", Q_NULLPTR));
        pushButton->setText(QApplication::translate("DownloadArea", ">", Q_NULLPTR));
        label_2->setText(QApplication::translate("DownloadArea", "There is no active task.", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DownloadArea: public Ui_DownloadArea {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOWNLOADAREA_H
