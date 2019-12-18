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

SecondUI::SecondUI(MainView *parent) :
  QListWidget(nullptr),
  ui(new Ui::SecondUI)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: #fafafa;");
    QStringList *listering = new QStringList;
    availablePackages = new QApt::PackageList;
    QApt::PackageList pkgList = parent->m_backend.availablePackages();

    ui->listWidget->setAlternatingRowColors(true);

    int i = 0;
    while (i < pkgList.length()) {

        QApt::Package *pkg = pkgList.at(i);

        if (pkg->isInstalled() != true) {
            if (pkgList.at(i)->isForeignArch() == true) {
                listering->append(pkg->name());
            }
        } else {
            availablePackages->append(pkg);
        }
        i++;
    }

    QFuture<QStringList *> future = QtConcurrent::run(SpecialEdits::runtime()->sortPackages, listering);
    m_watcher.setFuture(future);

    listON = m_watcher.result();

    i = 0;
    while (i < listON->length()) {
        ui->listWidget->addItem(listON->at(i));
        i++;
    }

    CURRENT = new QString;
    qDebug() << "Total amount of available packages for the current architecture: " + QString::number(i) + ".";
    qDebug() << "Total amount of available packages in all APT repositories: " + QString::number(pkgList.length()) + ".";

    connect(ui->listWidget, &QListWidget::itemDoubleClicked, this, [=]() { Q_EMIT packageWasSelected(new QString(ui->listWidget->currentItem()->text())); });
    old_Filter = new QString("All");

    i = 0;
}

SecondUI::~SecondUI()
{
    delete ui;
    CURRENT->~QString();
    old_list.~QList();
    m_watcher.~QFutureWatcher();
}

void SecondUI::handleValues(QString *ANP)
{
    ui->listWidget->addItem(*ANP);
}

void SecondUI::runFilter(QString *filter)
{
    int i = 0;
    if (filter != old_Filter) {

        ui->listWidget->clear();
        i = 0;

        if (filter == new QString("All")) {
            while (i < listON->length()) {
                ui->listWidget->addItem(listON->at(i));
                i++;
            }

        }
    }
}

void SecondUI::checkByChar(QString *value)
{
    int i = 0;

    if (value == QString("")) {
        ui->listWidget->clear();

        while (i < listON->length()) {
            ui->listWidget->addItem(listON->at(i));
            i++;
        }

    } else {
        ui->listWidget->clear();
        while (i < listON->length()) {

            if (QString(listON->at(i)).contains(value) == true) {
                ui->listWidget->addItem(listON->at(i));
            }
            i++;
        }
    }
}
