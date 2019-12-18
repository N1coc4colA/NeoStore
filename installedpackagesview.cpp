#include "installedpackagesview.h"
#include "ui_installedpackagesview.h"

#include <QSpacerItem>
#include <QFutureWatcher>
#include <QtConcurrent/QtConcurrent>
#include <mainview.h>
#include <QPushButton>
#include <QLabel>
#include <QListWidget>
#include <QHBoxLayout>

InstalledPackagesView::InstalledPackagesView(QApt::PackageList *list, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InstalledPackagesView)
{
    ui->setupUi(this);

    int i = 0;

    QStringList *listering = new QStringList;

    while (i < list->length()) {
        if (list->at(i)->isInstalled()) {
            listering->append(list->at(i)->name());
        }
        i++;
    }

    QFutureWatcher<QStringList *> m_watcher;
    QFuture<QStringList *> future = QtConcurrent::run(SpecialEdits::runtime()->sortPackages, listering);
    m_watcher.setFuture(future);

    i = 0;
    while (i < list->length()) {
        ui->listWidget->addItem(m_watcher.result()->at(i));
        i++;
    }

    connect(ui->listWidget, &QListWidget::doubleClicked, this, [=]() { Q_EMIT clicker(new QString(ui->listWidget->currentItem()->text())); });
    connect(ui->pushButton, &QPushButton::clicked, this, [=]() { Q_EMIT closing(); this->close(); });
    connect(ui->listWidget, &QListWidget::itemDoubleClicked, this, [=]() { Q_EMIT itemWasClicked(new QString(ui->listWidget->currentItem()->text())); });
}
