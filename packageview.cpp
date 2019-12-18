#include "packageview.h"
#include "ui_packageview.h"

#include <apt-pkg/depcache.h>
#include <QApt/DebFile>
#include <QApt/Package>
#include <QFile>
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
    PARENT->~MainView();
}

void PackageData::init(QString *m_pkg)
{
    m_package = PARENT->m_backend.package(*m_pkg);

    if (m_package->name() != "" && m_package != nullptr && m_package->name() != old_pkg){
        old_pkg = m_package->name();
        ui->AppName->setText(m_package->name());
        ui->AppSection->setText(m_package->section());
        ui->AppMaintain->setText(m_package->maintainer());
        ui->AppVer->setText(m_package->version());
        ui->AppDesc->setText(m_package->shortDescription());
        ui->dsize->setText(QString("Download size: %1 bytes").arg(QString::number(m_package->availableInstalledSize())));
        ui->isize->setText(QString(""));

        QSize *sizing = new QSize(100, 100);
        QIcon::Mode mode = QIcon::Mode::Normal;
        QIcon::State state = QIcon::State::Off;
        QString *path = new QString("/usr/share/icons/Papirus/64x64/apps/");
        QString truePath(QString::fromStdString(path->toStdString() + QString(m_package->name()).toStdString() + QString(".svg").toStdString()));
        QFile appfile(truePath);

        if (appfile.exists() == true) {
            ui->label_7->setPixmap(QIcon::fromTheme(m_package->name()).pixmap(*sizing, mode, state));
        } else {
            QFile secondOP(QString("/usr/share/icons/deepin/apps/128") + QString(m_package->name()) + QString(".svg"));
            if (secondOP.exists() == true) {
                ui->label_7->setPixmap(QIcon::fromTheme(m_package->name()).pixmap(*sizing, mode, state));
            } else {
                ui->label_7->setPixmap(QIcon::fromTheme("muon").pixmap(*sizing, mode, state));
            }
        }

        if (m_package->isInstalled()) {
            ui->isize->setText(QString("Installed size on disk: %1 bytes ").arg(QString::number(m_package->currentInstalledSize())));

            ui->ActionBtn->setText("Uninstall");

            if (isUpdateAvailable(m_package)) {
                ui->UpdateBtn->setText("Update");
                connect(ui->UpdateBtn, &QPushButton::clicked, this, [=]() {QApt::PackageList l; l.append(m_package); PARENT->m_backend.markPackages(l, QApt::Package::State::ToUpgrade); PARENT->runtime->pkgToUpdate.append(m_package->name());});
                if (PARENT->runtime->checkIfToUpdate(new QString(m_package->name())) == true) {
                    ui->UpdateBtn->setText("Cancel Update");
                    connect(ui->UpdateBtn, &QPushButton::clicked, this, [=]() {QApt::PackageList l; l.append(m_package); PARENT->m_backend.markPackages(l, QApt::Package::State::ToKeep); });
                }
            } else {
                ui->UpdateBtn->setVisible(false);
            }
            connect(ui->ActionBtn, &QPushButton::clicked, this, [=]() { PARENT->m_backend.markPackageForRemoval(m_package->name()); });

        } else {
            ui->ActionBtn->setText("Install");
            ui->UpdateBtn->setVisible(false);
            connect(ui->ActionBtn, &QPushButton::clicked, this, [=]() { PARENT->m_backend.markPackageForInstall(m_package->name()); PARENT->runtime->pkgToInstall.append(m_package->name()); });
            if (PARENT->runtime->checkIfToInstall(new QString(m_package->name())) == true) {
                ui->UpdateBtn->setText("Cancel Install");
                connect(ui->UpdateBtn, &QPushButton::clicked, this, [=]() {QApt::PackageList l; l.append(m_package); PARENT->m_backend.markPackages(l, QApt::Package::State::ToKeep); });
            }
        }

    } else {
        qDebug() << "Looks like you've selected an unregistered package... maybe it's a bug...";
    }
}

void PackageData::fileOpenedWithPath(QString *fPath)
{
    QApt::DebFile *f_package = new QApt::DebFile(*fPath);

    if (f_package->packageName() != "" && f_package != nullptr){

        ui->AppName->setText(f_package->packageName());
        ui->AppSection->setText(f_package->section());
        ui->AppMaintain->setText(f_package->maintainer());
        ui->AppVer->setText(f_package->version());
        ui->AppDesc->setText(f_package->shortDescription());
        ui->dsize->setText(QString(""));
        ui->isize->setText(QString(""));

        QSize *sizing = new QSize(100, 100);
        QIcon::Mode mode = QIcon::Mode::Normal;
        QIcon::State state = QIcon::State::Off;
        QString *path = new QString("/usr/share/icons/Papirus/64x64/apps/");
        QString truePath(QString::fromStdString(path->toStdString() + QString(f_package->packageName()).toStdString() + QString(".svg").toStdString()));
        QFile appfile(truePath);

        if (appfile.exists() == true) {
            ui->label_7->setPixmap(QIcon::fromTheme(f_package->packageName()).pixmap(*sizing, mode, state));
        } else {
            QFile secondOP(QString("/usr/share/icons/deepin/apps/128") + QString(f_package->packageName()) + QString(".svg"));
            if (secondOP.exists() == true) {
                ui->label_7->setPixmap(QIcon::fromTheme(f_package->packageName()).pixmap(*sizing, mode, state));
            } else {
                ui->label_7->setPixmap(QIcon::fromTheme("muon").pixmap(*sizing, mode, state));
            }
        }

        if (PARENT->m_backend.package(f_package->packageName())->isInstalled()) {
            ui->isize->setText(QString("System version: %1, file version: %2 ").arg(PARENT->m_backend.package(f_package->packageName())->version()).arg(f_package->version()));

            ui->ActionBtn->setText("Uninstall");
            ui->UpdateBtn->setVisible(false);
            connect(ui->ActionBtn, &QPushButton::clicked, this, [=]() { PARENT->m_backend.markPackageForRemoval(f_package->packageName()); });

        } else {
            ui->ActionBtn->setText("Install");
            ui->UpdateBtn->setVisible(false);
            connect(ui->ActionBtn, &QPushButton::clicked, this, [=]() { PARENT->m_backend.installFile(*f_package); });
        }

    } else {
        qDebug() << "Looks like you've selected an unregistered package... maybe it's a bug...";
    }
}

void PackageData::closingOn()
{
    Q_EMIT closing();
}
