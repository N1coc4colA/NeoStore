#include "mainview.h"
#include "ui_mainview.h"
#include "start.h"
#include "downloadpage.h"
#include "ndeclarative.h"

#include <QMainWindow>
#include <QUuid>
#include <DebconfKDE/DebconfGui.h>
#include <KF5/KIOCore/KProtocolManager>
#include <KF5/KIOCore/kiocore_export.h>
#include <QProcess>
#include <QDir>

DWIDGET_USE_NAMESPACE

class UpdatePage;

MainView::MainView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainView)
{
    m_backend.init();
    runtime = new SpecialEdits;

    ui->setupUi(this);

    popuping = new DownloadArea;
    TITLEBAR = new DTitlebar;
    LINER = new DLineEdit;
    scdL = new QVBoxLayout;
    tL = new QHBoxLayout;
    reloadedL = new QVBoxLayout;
    APPLYER = new QPushButton(this);
    pkgView = new PackageData(this);

    DBlurEffectWidget *sideBar = new DBlurEffectWidget;
    QWidget *titling = new QWidget;
    const QIcon what = QIcon();

    popuping->shadowing();

    sideBar->setFixedWidth(300);
    sideBar->setBlendMode(DBlurEffectWidget::BehindWindowBlend);
    sideBar->setMaskColor(DBlurEffectWidget::LightColor);
    sideBar->setLayout(scdL);

    LINER->setToolTip("Package name to search");
    LINER->setPlaceholderText("Search");

    TITLEBAR->setIcon(what);
    TITLEBAR->setTitle("");

    titling->setFixedHeight(40);
    titling->setStyleSheet("background-color: rgba(255,255,255,0.2);");

    scdL->addWidget(titling);
    scdL->setMargin(0);
    scdL->setMargin(0);

    tL->setContentsMargins(5, 5, 5, 5);
    tL->addWidget(LINER);

    titling->setLayout(tL);

    ui->sbL->addWidget(sideBar);
    ui->randomL->addWidget(TITLEBAR);

    pkgView->setVisible(false);

    connect(pkgView, &PackageData::closing, this, &MainView::viewList);

    TITLEBAR->setStyleSheet("background-color: #00000000;");

    loadData();
    DThemeManager::instance()->setTheme("dlight");

    APPLYER->setFixedSize(30, 30);
    APPLYER->move(305, 5);
    APPLYER->setText("");
    APPLYER->setIcon(QIcon::fromTheme("checkbox"));

    connect(APPLYER, &QPushButton::clicked, this, &MainView::startCommiting);
    connect(LINER, &DLineEdit::textEdited, this, [=]() { m_listing->checkByChar(new QString(LINER->text())); showListing(); });
}

MainView::~MainView()
{
    delete ui;
}

void MainView::packageView()
{
    QWidget *tmp = new QWidget;
    QSpacerItem *VS = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

    // Objects construction and/or their initialization.
    viewer = new BookPage;
    m_listing = new SecondUI(this);
    m_categories = new Categories;
    pageUp = new UpdatePage(this);

    //Set up the UI.
    viewer->init(new QString("Top"));
    m_listing->setVisible(false);
    pageUp->setVisible(false);
    ui->horizontalLayout->addWidget(viewer);
    ui->horizontalLayout->addWidget(m_listing);
    ui->horizontalLayout->addWidget(pkgView);
    ui->horizontalLayout->addWidget(pageUp);

    scdL->addWidget(m_categories);
    scdL->addItem(VS);
    scdL->addWidget(popuping);

    tmp->setVisible(false);

    connect(m_categories, SIGNAL(showLister()), this, SLOT(showListing()));
    connect(m_categories, &Categories::showCategory, viewer, &BookPage::init);
    connect(m_categories, &Categories::showCategory, this, &MainView::viewList);
    connect(viewer, &BookPage::openView, this, &MainView::setPV);
    connect(m_listing, SIGNAL(packageWasSelected(QString*)), this, SLOT(setPV(QString*)));
    connect(pkgView, &PackageData::closing, [=]() { m_listing->setVisible(true); viewer->setVisible(false); });
    connect(m_categories, &Categories::callUpdatesView, this, [=]() {showListing(); m_listing->setVisible(false); pageUp->setVisible(true);});

    qDebug() << "MainView component initialization finished, alias w, the window.";
}

void MainView::showListing()
{
    m_listing->setVisible(true);
    viewer->setVisible(false);
    pkgView->setVisible(false);
    pageUp->setVisible(false);
}

void MainView::viewList()
{
    m_listing->setVisible(false);
    viewer->setVisible(true);
    pkgView->setVisible(false);
    pageUp->setVisible(false);
}

void MainView::loadData()
{
    QDir directory("/tmp/nui");

    if (!directory.exists()) {
        Start *prevent = new Start;
        prevent->show();
        QProcess *downloadDB = new QProcess;
        QString command = "rm -f -r /tmp/nui";
        QString command2 = "mkdir /tmp/nui";
        QString command3 = "cd /tmp/nui";
        QString command4 = "git clone https://www.github.com/N1coc4colA/NeoStore-WebContent /tmp/nui";

        downloadDB->startDetached(command);
        downloadDB->waitForFinished();
        qDebug() << downloadDB->readAllStandardOutput();

        downloadDB->startDetached(command2);
        downloadDB->waitForFinished();
        qDebug() << downloadDB->readAllStandardOutput();
        downloadDB->startDetached(command3);
        downloadDB->waitForFinished();
        qDebug() << downloadDB->readAllStandardOutput();

        downloadDB->startDetached(command4);
        downloadDB->waitForFinished();
        qDebug() << downloadDB->readAllStandardOutput();
    } else {}
    packageView();
}

void MainView::startCommiting()
{
    if (!m_backend.markedPackages().isEmpty()) {
    m_transaction = m_backend.commitChanges();

    NDeclarative *grant_declaration = new NDeclarative;

    // NDeclarative is used to declare the future changes that will be applyed and get the user grant before setting any changes.
    // List order to pass (of QApt::Package::State):
    // ToInstall, ToRemove, ToUpgrade, ToReInstall, ToDowngrade
    // For the moment it have some errors to show the Qstrings in the list...

    grant_declaration->setPKGList(m_backend);
    grant_declaration->show();

    connect(grant_declaration, &NDeclarative::sessionAccepted, this, [=] () {
        // Provide proxy/locale to the transaction
        qDebug() << "Session have been accepted.";
        if (KProtocolManager::proxyType() == KProtocolManager::ManualProxy) {
            m_transaction->setProxy(KProtocolManager::proxyFor("http"));
        }

        m_transaction->setLocale(QLatin1String(setlocale(LC_MESSAGES, nullptr)));
        popuping->setUP(m_transaction);
        m_transaction->run();
        connect(m_transaction, &QApt::Transaction::finished, &m_backend, &QApt::Backend::reloadCache);
    }); }

    qDebug() << "finished.";
}

void MainView::setPV(QString *data)
{
    qDebug() << data;
    pkgView->init(data);
    viewer->setVisible(false);
    m_listing->setVisible(false);
    pkgView->setVisible(true);
    pageUp->setVisible(false);
}
