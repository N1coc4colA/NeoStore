#include "packageview.h"
#include "ui_packageview.h"
#include <QPointer>
#include <QLabel>
#include <QDebug>

PackageData::PackageData(MainView *parent) :
    QWidget(nullptr),
    ui(new Ui::PackageData)
{
    ui->setupUi(this);
    connect(ui->closeBtn, SIGNAL(clicked()), this, SLOT(closingOn()));
    PARENT = parent;
}

PackageData::~PackageData()
{
    delete ui;
    m_package->~Package();
}

void PackageData::init(QString *m_pkg)
{
    m_package = PARENT->m_backend.package(*m_pkg);
    if (m_package->name() != "" && m_package != nullptr){
        ui->AppName->setText(m_package->name());
        ui->AppSection->setText(m_package->section());
        ui->AppMaintain->setText(m_package->maintainer());
        ui->AppVer->setText(m_package->version());
        ui->AppDesc->setText(m_package->shortDescription());

        if (m_package->isInstalled()) {

            ui->ActionBtn->setText("Uninstall");
            if (m_package->state() & QApt::Package::Upgradeable) {
                ui->UpdateBtn->setText("Update");
                connect(ui->UpdateBtn, &QPushButton::clicked, this, [=]() {QApt::PackageList l; l.append(m_package); PARENT->m_backend.markPackages(l, QApt::Package::State::ToUpgrade); });
            } else {
                ui->UpdateBtn->setVisible(false);
            }
            connect(ui->ActionBtn, &QPushButton::clicked, this, [=]() { PARENT->m_backend.markPackageForRemoval(m_package->name()); });

        } else {
            ui->ActionBtn->setText("Install");
            ui->UpdateBtn->setVisible(false);
            connect(ui->ActionBtn, &QPushButton::clicked, this, [=]() { PARENT->m_backend.markPackageForInstall(m_package->name()); });
        }

    } else {
        qDebug() << "Looks like you've selected an unregistered package... maybe it's a bug...";
    }
}

void PackageData::closingOn()
{
    Q_EMIT closing();
}
