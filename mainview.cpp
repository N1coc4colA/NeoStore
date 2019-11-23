#include "mainview.h"
#include "ui_mainview.h"
#include "start.h"

#include <QProcess>
#include <QDebug>
#include <QDir>

DWIDGET_USE_NAMESPACE

MainView::MainView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainView)
{
    m_backend.init();

    this->setWindowIcon(QIcon("application-x-deb"));
    ui->setupUi(this);
    ui->Main->setStyleSheet("background: #fff");

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
    QWidget *LOGO = new QWidget;


    sideBar->setFixedWidth(300);
    sideBar->setBlendMode(DBlurEffectWidget::BehindWindowBlend);
    sideBar->setMaskColor(DBlurEffectWidget::LightColor);
    sideBar->setLayout(scdL);

    LINER->setToolTip("Package name to search");
    LINER->setPlaceholderText("Search");

    TITLEBAR->setIcon(what);
    TITLEBAR->setTitle("                                   ");

    titling->setFixedHeight(40);
    titling->setStyleSheet("background-color: rgba(255,255,255,0.2);");

    scdL->addWidget(titling);
    scdL->setMargin(0);
    scdL->setMargin(0);

    tL->setContentsMargins(5, 5, 5, 5);
    tL->addWidget(LOGO);
    tL->addWidget(LINER);

    LOGO->setStyleSheet("border-image: url(:/logo.png) 0 0 0 0 stretch stretch; border-radius: 4px;");
    LOGO->setFixedWidth(30);

    titling->setLayout(tL);

    ui->sbL->addWidget(sideBar);
    ui->randomL->addWidget(TITLEBAR);

    pkgView->setVisible(false);

    connect(pkgView, &PackageData::closing, this, &MainView::viewList);

    TITLEBAR->setStyleSheet("background-color: #00000000;");

    loadData();
    DThemeManager::instance()->setTheme("dlight");

    APPLYER->setFixedHeight(30);
    APPLYER->move(305, 5);
    APPLYER->setText("Apply changes");

    connect(APPLYER, &QPushButton::clicked, this, &MainView::startCommiting);
}

MainView::~MainView()
{
    delete ui;
}

void MainView::packageView()
{
    QWidget *tmp = new QWidget;
    tmp->setVisible(false);
    m_categories = new Categories;
    scdL->addWidget(m_categories);

    viewer = new BookPage;
    ui->horizontalLayout->addWidget(viewer);
    viewer->init(new QString("Top"));
    m_listing = new SecondUI(this);
    m_listing->setVisible(false);
    ui->horizontalLayout->addWidget(m_listing);
    ui->horizontalLayout->addWidget(pkgView);

    connect(m_categories, SIGNAL(showLister()), this, SLOT(showListing()));
    connect(m_categories, &Categories::showCategory, viewer, &BookPage::init);
    connect(m_listing, SIGNAL(packageWasSelected(QString*)), this, SLOT(setPV(QString*)));
    connect(pkgView, &PackageData::closing, [=]() { m_listing->setVisible(true); viewer->setVisible(false); });
}

void MainView::showListing()
{
    m_listing->setVisible(true);
    viewer->setVisible(false);
    pkgView->setVisible(false);
}

void MainView::viewList()
{
    m_listing->setVisible(false);
    viewer->setVisible(true);
    pkgView->setVisible(false);
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
    m_transaction = m_backend.commitChanges();
    int i = 0;

    while ( i < m_backend.markedPackages().length()) {
        qDebug() << m_backend.markedPackages().at(i)->name();
        i++;
    }

    qDebug() << "finished.";
}

void MainView::setPV(QString *data)
{
    pkgView->init(data);
    viewer->setVisible(false);
    m_listing->setVisible(false);
    pkgView->setVisible(true);
}
