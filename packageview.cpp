#include "packageview.h"
#include "ui_packageview.h"

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
    qDebug() << QString::number(m_package->state());

    if (m_package->name() != "" && m_package != nullptr){
        ui->AppName->setText(m_package->name());
        ui->AppSection->setText(m_package->section());
        ui->AppMaintain->setText(m_package->maintainer());
        ui->AppVer->setText(m_package->version());
        ui->AppDesc->setText(m_package->shortDescription());
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

            ui->ActionBtn->setText("Uninstall");

            if (isUpdateAvailable(m_package)) {
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
