#include "secondui.h"
#include "ui_secondui.h"
#include "localfilter.h"

#include <QApt/Backend>
#include <QFutureWatcher>
#include <QDebug>
#include <QLabel>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QtConcurrent/QtConcurrent>
#include <QListWidgetItem>
#include <QFutureWatcher>

bool packageNameLessThan(QString p1, QString p2)
{
     return p1 < p2;
}

QStringList *sortPackages(QStringList *list)
{
    std::sort(list->begin(), list->end(), packageNameLessThan);
    return list;
}

SecondUI::SecondUI(MainView *parent) :
  QListWidget(nullptr),
  ui(new Ui::SecondUI)
{
    PARENT = parent;
    ui->setupUi(this);
    this->setStyleSheet("background-color: #f0f0f0;");
    QStringList *listering = new QStringList;
    QApt::PackageList pkgList = parent->m_backend.availablePackages();

    int i = 0;
    while (i < pkgList.length()) {
        if (pkgList.at(i)->isForeignArch() == true) {
            listering->append(QString(pkgList.at(i)->name()));
        }
        i++;
    }

    QFutureWatcher<QStringList *> m_watcher;
    QFuture<QStringList *> future = QtConcurrent::run(sortPackages, listering);
    m_watcher.setFuture(future);

    qDebug() << "1st step right.";

    QStringList *listON = m_watcher.result();

    i = 0;
    while (i < listering->length()) {
        ui->listWidget->addItem(listON->at(i));
        i++;
    }

    CURRENT = new QString;
    qDebug() << "Total amount of available packages " + QString::number(i) + ".";

    connect(ui->listWidget, &QListWidget::currentItemChanged, this, [=]() { Q_EMIT packageWasSelected(new QString(ui->listWidget->currentItem()->text())); });
}

SecondUI::~SecondUI()
{
    delete ui;
    CURRENT->~QString();
}

void SecondUI::handleValues(QString *ANP)
{
    ui->listWidget->addItem(*ANP);
}
