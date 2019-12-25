#include "packageview.h"
#include "ui_packageview.h"

#include <apt-pkg/depcache.h>
#include <QApt/DebFile>
#include <QApt/Package>
#include <QFile>
#include <QPointer>
#include <QLabel>
#include <ddialog.h>
#include <QDebug>

DWIDGET_USE_NAMESPACE

PackageData::PackageData(MainView *parent) :
    QWidget(nullptr),
    ui(new Ui::PackageData)
{
    screenshotWidget = new ScreenShotWidget;
    ui->setupUi(this);
    ui->horizontalLayout_5->addWidget(screenshotWidget);
    screenshotWidget->setVisible(false);
    connect(ui->closeBtn, SIGNAL(clicked()), this, SLOT(closingOn()));
    PARENT = parent;
    ui->ReInstallBtn->setText("Reinstall");
    ui->DowngradeBtn->setText("Downgrade");
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
    tmpName = *m_pkg;

    if (m_package->name() != "" && m_package != nullptr && m_package->name() != old_pkg){
        load();
    } else {
        qDebug() << "Looks like you've selected an unregistered package... maybe it's a bug...";
    }
}

void PackageData::load()
{
    a = false;

    qDebug() << QString::number(m_package->state());

    old_pkg = m_package->name();
    ui->AppName->setText(m_package->name());
    ui->AppSection->setText(m_package->section());
    ui->AppMaintain->setText(m_package->maintainer());
    ui->AppVer->setText(m_package->version());
    ui->AppDesc->setText(m_package->shortDescription());
    ui->dsize->setText(QString("Download size: %1 bytes").arg(QString::number(m_package->availableInstalledSize())));
    ui->isize->setText(QString(""));
    ui->listWidget_2->clear();
    ui->listWidget->clear();

    qDebug() << m_package->screenshotUrl(QApt::ScreenshotType::Screenshot);
    QUrl SSUrl(m_package->screenshotUrl(QApt::ScreenshotType::Screenshot));
    if (SSUrl.isEmpty() == false && SSUrl != QUrl("") && SSUrl != QUrl(" ") && (QString(SSUrl.toString(QUrl::None)).contains("http:/") == true || QString(SSUrl.toString(QUrl::None)).contains("https:/") == true)) {
        ui->label_5->setVisible(false);
        screenshotWidget->setVisible(true);
        qDebug() << SSUrl;
        screenshotWidget->load(&SSUrl);
     } else {
        ui->label_5->setVisible(true);
        screenshotWidget->setVisible(false);
    }

    //This loop is needed to remove the meta tag <b></b> when calling installed files.
    int i = 0;

    while ( i < m_package->dependencyList(true).length()) {
        ui->listWidget->addItem(QString(m_package->dependencyList(true).at(i)).replace(QRegExp("</[a-z]>"), "").replace(QRegExp("<[a-z]>"), ""));
        i++;
    }

    if (m_package->installedFilesList().length() > 0) {
        ui->listWidget_2->addItems(m_package->installedFilesList());
        a = true;
    } else {
        a = false;
    }

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
        ui->ReInstallBtn->setVisible(true);
        ui->DowngradeBtn->setVisible(true);
        connect(ui->UpdateBtn, &QPushButton::clicked, this, [=]() {QApt::PackageList l; l.append(m_package); PARENT->m_backend.markPackages(l, QApt::Package::State::ToReInstall); });

        if (isUpdateAvailable(m_package)) {
            ui->UpdateBtn->setVisible(true);
            ui->UpdateBtn->setText("Update");
            connect(ui->UpdateBtn, &QPushButton::clicked, this, [=]() {QApt::PackageList l; l.append(m_package); PARENT->m_backend.markPackages(l, QApt::Package::State::ToUpgrade); PARENT->runtime->pkgToUpdate.append(m_package->name());});
            if (m_package->state() & QApt::Package::State::ToUpgrade) {
                ui->UpdateBtn->setText("Cancel Update");
                connect(ui->UpdateBtn, &QPushButton::clicked, this, [=]() {QApt::PackageList l; l.append(m_package); PARENT->m_backend.markPackages(l, QApt::Package::State::ToKeep); });
            }
        } else {
            ui->UpdateBtn->setVisible(false);
        }
        connect(ui->ActionBtn, &QPushButton::clicked, this, [=]() { PARENT->m_backend.markPackageForRemoval(m_package->name()); });

    } else {
        ui->UpdateBtn->setVisible(false);
        ui->DowngradeBtn->setVisible(false);
        ui->ReInstallBtn->setVisible(false);

        ui->ActionBtn->setText("Install");
        connect(ui->ActionBtn, &QPushButton::clicked, this, [=]() { PARENT->m_backend.markPackageForInstall(m_package->name()); PARENT->runtime->pkgToInstall.append(m_package->name()); });
        if (PARENT->runtime->checkIfToInstall(new QString(m_package->name())) == true) {
            ui->UpdateBtn->setText("Cancel Install");
            connect(ui->UpdateBtn, &QPushButton::clicked, this, [=]() {QApt::PackageList l; l.append(m_package); PARENT->m_backend.markPackages(l, QApt::Package::State::ToKeep); });
        }
    }


    if (m_package->state() & QApt::Package::State::ToInstall) {
        ui->ActionBtn->setText("Cancel Installation");
        connect(ui->ActionBtn, &QPushButton::clicked, this, [=]() {QApt::PackageList l; l.append(m_package); PARENT->m_backend.markPackages(l, QApt::Package::State::ToKeep); });
    } else { if (m_package->state() & QApt::Package::State::ToRemove) {
        ui->ActionBtn->setText("Cancel Uninstallation");
        connect(ui->ActionBtn, &QPushButton::clicked, this, [=]() {QApt::PackageList l; l.append(m_package); PARENT->m_backend.markPackages(l, QApt::Package::State::ToKeep); });
    } }

    showFL(a);
}

//Don't use load() for open file with. In deb file and APT package list, the classes aren't the same and some functions aren't the same, are missing or in added,
//Compared to QApt::DebFile and QApt::Package.
//Like for DebFile, when I look for the deps. or installed files (don't know which of the two) makes the app crash, so hide the widgets when using a local file.
//I think that it will be the same for the screenshot area, or I'll put a message at the place of the @nextTwoWeeksSupportScreenshot, that tells that it's not supported.

void PackageData::fileOpenedWithPath(QString *fPath)
{
    QApt::DebFile *f_package = new QApt::DebFile(*fPath);

    if (f_package->packageName() != "" && f_package != nullptr && f_package->isValid()){

        ui->AppName->setText(f_package->packageName());
        ui->AppSection->setText(f_package->section());
        ui->AppMaintain->setText(f_package->maintainer());
        ui->AppVer->setText(f_package->version());
        ui->AppDesc->setText(f_package->shortDescription());
        ui->dsize->setText(QString(""));
        ui->isize->setText(QString(""));
        ui->listWidget_2->clear();
        ui->listWidget->clear();
        showFL(false);


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

        ui->label_5->setVisible(true);
        screenshotWidget->setVisible(false);

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

void PackageData::showFL(bool value)
{
    ui->depsWidget->setVisible(value);
}
