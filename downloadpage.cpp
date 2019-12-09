#include "downloadpage.h"
#include "ui_downloadpage.h"
#include "mainview.h"
#include "installedpackagesview.h"

class SpecialEdits;

UpdatePage::UpdatePage(MainView *parent) :
    QWidget(parent),
    ui(new Ui::UpdatePage)
{
    qDebug() << "UpdatePage component initialization started, alias pageUp.";
    ui->setupUi(this);
    int i = 0;

    qDebug() << "UpdatePage component initialization, getting available updates list.";
    QApt::PackageList *list = parent->m_listing->availablePackages;
    QApt::PackageList updates;

    while( i < list->length()) {
        if (list->at(i)->version() < list->at(i)->availableVersion()) {
            ui->listWidget->addItem(list->at(i)->name());
            updates.append(list->at(i));
        }
        i++;
    }
    qDebug() << "UpdatePage component initialization finished, without alias.";

    i = 0;

    qDebug() << "Available updtaes: " + QString::number(ui->listWidget->count());
    ui->mainUp->setVisible(true);
    ui->willet->setVisible(true);
    ui->widget_3->setVisible(false);

    connect(ui->pushButton_2, &QPushButton::clicked, this, [=]() { openIPV(list); });
    connect(ui->pushButton, &QPushButton::clicked, this, [=]() {parent->m_backend.markPackages(updates, QApt::Package::ToUpgrade);});

    qDebug() << "UpdatePage component initialization finished, alias pageUp.";
}

UpdatePage::~UpdatePage()
{
    delete ui;
}

void UpdatePage::openIPV(QApt::PackageList *list)
{
    ui->mainUp->setVisible(false);
    InstalledPackagesView *running = new InstalledPackagesView(list);
    ui->listLayout->addWidget(running); running->setVisible(true);
    connect(running, &InstalledPackagesView::closing, this, &UpdatePage::closeIPV);
}

void UpdatePage::closeIPV()
{
    ui->mainUp->setVisible(true);
}
