#include "ndeclarative.h"

#include <QDebug>
#include <dimagebutton.h>
#include <QPushButton>
#include <QTreeWidget>
#include <QHeaderView>
#include <QFile>
#include <QTreeWidgetItem>
#include <QVBoxLayout>

DWIDGET_USE_NAMESPACE

NDeclarative::NDeclarative(QWidget *parent) : DDialog(parent)
{
}

void NDeclarative::setPKGList(QApt::Backend &m_backend)
{
    int i = 0;

    QList<QString*> *ToInstall = new QList<QString*>;
    QList<QString*> *ToUpdate = new QList<QString*>;
    QList<QString*> *ToRemove = new QList<QString*>;
    QList<QString*> *ToDowngrade = new QList<QString*>;
    QList<QString*> *ToReinstall = new QList<QString*>;

    QApt::CacheState states;

    QApt::PackageList tmp;
    QApt::PackageList lives;


    lives = m_backend.availablePackages();

    while ( i < lives.length()) {

        // see enum to see which refers to which.

        if (lives.at(i)->state() & QApt::Package::State::ToInstall) {
            ToInstall->append(new QString(lives.at(i)->name()));

        } if (lives.at(i)->state() & QApt::Package::State::ToRemove) {
            ToRemove->append(new QString(lives.at(i)->name()));

        } if (lives.at(i)->state() & QApt::Package::State::ToDowngrade) {
            ToDowngrade->append(new QString(lives.at(i)->name()));

        } if (lives.at(i)->state() & QApt::Package::State::ToReInstall) {
            ToReinstall->append(new QString(lives.at(i)->name()));

        } if (lives.at(i)->state() & QApt::Package::State::ToUpgrade) {
            ToUpdate->append(new QString(lives.at(i)->name()));

        }
        i++;
    }
    QPushButton *grant = new QPushButton;
    QPushButton *decline = new QPushButton;
    QVBoxLayout *mainL = new QVBoxLayout;
    QHBoxLayout *fL = new QHBoxLayout;
    QTreeWidget *widget = new QTreeWidget;

    decline->setText("Cancel");
    grant->setText("Apply");
    fL->addWidget(decline);
    fL->addWidget(grant);

    i = 0;
    if (!ToInstall->isEmpty()) {
        QTreeWidgetItem *TTI = new QTreeWidgetItem;
        TTI->setText(0, "To install:");
        widget->addTopLevelItem(TTI);
        while ( i < ToInstall->length() ) {
            QTreeWidgetItem *item = new QTreeWidgetItem;
            item->setText(0, *ToInstall->at(i));
            TTI->addChild(item);
            i++;
        }
        i = 0;
    }

    if (!ToRemove->isEmpty()) {
        QTreeWidgetItem *TTR = new QTreeWidgetItem;
        TTR->setText(0, "To remove:");
        widget->addTopLevelItem(TTR);
        while ( i < ToRemove->length() ) {
            QTreeWidgetItem *item = new QTreeWidgetItem;
            item->setText(0, *ToRemove->at(i));
            TTR->addChild(item);
            i++;
        }
        i = 0;
    }

    if (!ToUpdate->isEmpty()) {
        QTreeWidgetItem *TTU = new QTreeWidgetItem;
        TTU->setText(0, "To Update:");
        widget->addTopLevelItem(TTU);
        while ( i < ToUpdate->length() ) {
            QTreeWidgetItem *item = new QTreeWidgetItem;
            item->setText(0, *ToUpdate->at(i));
            TTU->addChild(item);
            i++;
        }
        i = 0;
    }

    if (!ToReinstall->isEmpty()) {
        QTreeWidgetItem *TTRI = new QTreeWidgetItem;
        TTRI->setText(0, "To reinsrtall:");
        widget->addTopLevelItem(TTRI);
        while ( i < ToReinstall->length() ) {
            QTreeWidgetItem *item = new QTreeWidgetItem;
            item->setText(0, *ToReinstall->at(i));
            TTRI->addChild(item);
            i++;
        }
        i = 0;
    }

    if (!ToDowngrade->isEmpty()) {
        QTreeWidgetItem *TTD = new QTreeWidgetItem;
        TTD->setText(0, "To downgrade:");
        widget->addTopLevelItem(TTD);
        while ( i < ToDowngrade->length() ) {
            QTreeWidgetItem *item = new QTreeWidgetItem;
            item->setText(0, *ToDowngrade->at(i));
            TTD->addChild(item);
            i++;
        }
        i = 0;
    }

    mainL->addWidget(widget);
    mainL->addLayout(fL);
    QWidget *mainW = new QWidget;
    mainW->setLayout(mainL);
    this->addContent(mainW);
    mainW->setStyleSheet("background-color: #fff; color: #000;");

    connect(grant, &QPushButton::clicked, this, [=] () {Q_EMIT sessionAccepted(); close();});
    connect(decline, &QPushButton::clicked, this, [=] () {Q_EMIT sessionDown(); close();});

    QFile file(":/styles/ndeclarative.qtreeview.css");
    file.open(QFile::ReadOnly);
    widget->setStyleSheet(file.readAll());
    widget->header()->setVisible(false);
}
