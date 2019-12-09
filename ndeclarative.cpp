#include "ndeclarative.h"

#include <QDebug>
#include <dimagebutton.h>
#include <QPushButton>
#include <QListWidget>
#include <QLabel>
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

    while ( i < m_backend.markedPackages().length()) {
        qDebug() << m_backend.markedPackages().at(i)->name();
        qDebug() << m_backend.markedPackages().at(i)->state();

        // see enum to see which refers to which.

        if (m_backend.markedPackages().at(i)->state() == QApt::Package::State::ToInstall) {
            const QString vala = m_backend.markedPackages().at(i)->name();
            qDebug() << vala;
            ToInstall->append(new QString(m_backend.markedPackages().at(i)->name()));
            qDebug() << m_backend.markedPackages().at(i)->name();
        } if (m_backend.markedPackages().at(i)->state() == QApt::Package::State::ToRemove) {
            const QString vala = m_backend.markedPackages().at(i)->name();
            qDebug() << vala;
            ToRemove->append(new QString(m_backend.markedPackages().at(i)->name()));
            qDebug() << m_backend.markedPackages().at(i)->name();
        } if (m_backend.markedPackages().at(i)->state() == QApt::Package::State::ToDowngrade) {
            const QString vala = m_backend.markedPackages().at(i)->name();
            qDebug() << vala;
            ToDowngrade->append(new QString(m_backend.markedPackages().at(i)->name()));
            qDebug() << m_backend.markedPackages().at(i)->name();
        } if (m_backend.markedPackages().at(i)->state() == QApt::Package::State::ToReInstall) {
            const QString vala = m_backend.markedPackages().at(i)->name();
            qDebug() << vala;
            ToReinstall->append(new QString(m_backend.markedPackages().at(i)->name()));
            qDebug() << m_backend.markedPackages().at(i)->name();
        } if (m_backend.markedPackages().at(i)->state() == QApt::Package::State::ToUpgrade) {
            qDebug() << "hohohoho!";
            const QString vala = m_backend.markedPackages().at(i)->name();
            qDebug() << vala;
            ToUpdate->append(new QString(m_backend.markedPackages().at(i)->name()));
            qDebug() << m_backend.markedPackages().at(i)->name();
        }
        i++;
    }

    qDebug() << "Session demand sent.";
    QPushButton *grant = new QPushButton;
    QPushButton *decline = new QPushButton;
    QVBoxLayout *mainL = new QVBoxLayout;
    QHBoxLayout *fL = new QHBoxLayout;

    decline->setText("Cancel");
    grant->setText("Apply");
    fL->addWidget(decline);
    fL->addWidget(grant);

    i = 0;
    if (!ToInstall->isEmpty()) {
        QLabel *TTI = new QLabel;
        QListWidget *LTI = new QListWidget;
        while ( i < ToInstall->length() ) {
            LTI->addItem(*ToInstall->at(i));
        }
        LTI->setFixedHeight(100);
        mainL->addWidget(TTI);
        mainL->addWidget(LTI);
        i = 0;
    }

    if (!ToRemove->isEmpty()) {
        QLabel *TTR = new QLabel;
        QListWidget *LTR = new QListWidget;
        while ( i < ToInstall->length() ) {
            LTR->addItem(*ToInstall->at(i));
        }
        LTR->setFixedHeight(100);
        mainL->addWidget(TTR);
        mainL->addWidget(LTR);
        i = 0;
    }

    if (!ToUpdate->isEmpty()) {
        QLabel *TTU = new QLabel;
        QListWidget *LTU = new QListWidget;
        while ( i < ToInstall->length() ) {
            LTU->addItem(*ToInstall->at(i));
        }
        LTU->setFixedHeight(100);
        mainL->addWidget(TTU);
        mainL->addWidget(LTU);
        i = 0;
    }

    if (!ToReinstall->isEmpty()) {
        QLabel *TTRI = new QLabel;
        QListWidget *LTRI = new QListWidget;
        while ( i < ToInstall->length() ) {
            LTRI->addItem(*ToInstall->at(i));
        }
        LTRI->setFixedHeight(100);
        mainL->addWidget(TTRI);
        mainL->addWidget(LTRI);
        i = 0;
    }

    if (!ToDowngrade->isEmpty()) {
        QLabel *TTD = new QLabel;
        QListWidget *LTD = new QListWidget;
        while ( i < ToInstall->length() ) {
            LTD->addItem(*ToInstall->at(i));
        }
        mainL->addWidget(TTD);
        mainL->addWidget(LTD);
        i = 0;
    }

    mainL->addLayout(fL);
    QWidget *mainW = new QWidget;
    mainW->setLayout(mainL);
    this->addContent(mainW);
    mainW->setStyleSheet("background-color: #000;");

    connect(grant, &QPushButton::clicked, this, [=] () {Q_EMIT sessionAccepted(); qDebug() << "Sending demand for root access..."; close();});
    connect(decline, &QPushButton::clicked, this, [=] () {Q_EMIT sessionDown(); close();});

    qDebug() << "NDeclarative component initialization finished, alias viewer.";
}
