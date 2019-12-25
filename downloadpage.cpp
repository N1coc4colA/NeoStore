#include "downloadpage.h"
#include "ui_downloadpage.h"
#include "mainview.h"
#include "installedpackagesview.h"

class SpecialEdits;

UpdatePage::UpdatePage(MainView *parent) :
    QWidget(parent),
    ui(new Ui::UpdatePage)
{
    ui->setupUi(this);
    int i = 0;

    QApt::PackageList *list = parent->m_listing->availablePackages;
    QApt::PackageList updates;

    while( i < parent->m_backend.upgradeablePackages().length()) {
            ui->listWidget->addItem(parent->m_backend.upgradeablePackages().at(i)->name());
            updates.append(parent->m_backend.upgradeablePackages().at(i));
        i++;
    }

    i = 0;

    qDebug() << "Available updates: " + QString::number(ui->listWidget->count());

    if (ui->listWidget->count() > 10) {
       parent->m_categories->setAnIcon(QIcon(":/icons/numbers/more.svg"), parent->m_categories->Updates);
    } else {
        parent->m_categories->setAnIcon(QIcon(":/icons/numbers/" + QString::number(ui->listWidget->count()) + ".svg"), parent->m_categories->Updates);
    }

    ui->mainUp->setVisible(true);
    ui->willet->setVisible(true);
    ui->widget_3->setVisible(false);

    connect(ui->pushButton_2, &QPushButton::clicked, this, [=]() { openIPV(list); });
    connect(ui->pushButton, &QPushButton::clicked, this, [=]() {parent->m_backend.markPackages(updates, QApt::Package::ToUpgrade);});
    connect(ui->listWidget, &QListWidget::itemDoubleClicked, this, [=]() { Q_EMIT itemWasClicked(new QString(ui->listWidget->currentItem()->text())); });

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
    connect(running, &InstalledPackagesView::itemWasClicked, this, &UpdatePage::reSendClicked);
}

void UpdatePage::closeIPV()
{
    ui->mainUp->setVisible(true);
}

void UpdatePage::reSendClicked(QString *value)
{
    Q_EMIT itemWasClicked(value);
}
