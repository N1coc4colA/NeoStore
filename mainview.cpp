#include "mainview.h"
#include "ui_mainview.h"
#include "start.h"
#include "downloadpage.h"
#include "ndeclarative.h"
#include "about.h"
#include "contentdownloader.h"

#include <DApplication>
#include <QFileDialog>
#include <QMainWindow>
#include <ddialog.h>
#include <QUuid>
#include <DebconfKDE/DebconfGui.h>
#include <KF5/KIOCore/KProtocolManager>
#include <KF5/KIOCore/kiocore_export.h>
#include <QProcess>
#include <QDir>

DWIDGET_USE_NAMESPACE

class UpdatePage;

const QSize BS(30, 30);

MainView::MainView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainView)
{
    m_backend.init();
    oldWidget = nullptr;
    backwardWidget = nullptr;
    runtime = new SpecialEdits;
    QApt::CacheState cacheState;

    ui->setupUi(this);

    popuping = new DownloadArea;
    TITLEBAR = new DTitlebar;
    LINER = new DLineEdit;
    scdL = new QVBoxLayout;
    tL = new QHBoxLayout;
    reloadedL = new QVBoxLayout;
    APPLYER = new QPushButton(this);
    pkgView = new PackageData(this);

    QWidget *buttonArea = new QWidget(this);
    QHBoxLayout *btnL = new QHBoxLayout(buttonArea);
    QPushButton *SAVE = new QPushButton(buttonArea);
    QPushButton *RELOAD = new QPushButton(buttonArea);
    QPushButton *LOAD = new QPushButton(buttonArea);
    DBlurEffectWidget *sideBar = new DBlurEffectWidget;
    QWidget *titling = new QWidget;
    const QIcon what = QIcon();

    popuping->shadowing();

    sideBar->setFixedWidth(300);
    sideBar->setBlendMode(DBlurEffectWidget::BehindWindowBlend);
    sideBar->setMaskColor(QColor(05, 05, 05, 150));
    sideBar->setLayout(scdL);

    LINER->setToolTip("Package name to search");
    LINER->setPlaceholderText("Search");
    LINER->setClearButtonEnabled(true);
    LINER->setStyleSheet("border-radius: 4px;");

    TITLEBAR->setIcon(what);
    TITLEBAR->setTitle("");
    TITLEBAR->setMenu(initMenu());

    titling->setFixedHeight(40);
    titling->setStyleSheet("background-color: rgba(255,255,255,0);");

    scdL->addWidget(titling);
    scdL->setMargin(0);
    scdL->setMargin(0);

    tL->setContentsMargins(5, 5, 5, 5);
    tL->addWidget(LINER);

    titling->setLayout(tL);

    ui->sbL->addWidget(sideBar);
    ui->randomL->addWidget(TITLEBAR);

    pkgView->setVisible(false);

    TITLEBAR->setStyleSheet("background-color: #00000000;");

    LINER->setStyleSheet("QLineEdit {background: rgba(255, 255, 255, 0.5); border-radius: 2px;}");
    LINER->setFixedHeight(30);

    loadData();
    DThemeManager::instance()->setTheme(this, "light");
    DThemeManager::instance()->setTheme(LINER, "dark");

    SAVE->setFixedSize(BS);
    RELOAD->setFixedSize(BS);
    LOAD->setFixedSize(BS);
    SAVE->setText("");
    LOAD->setText("");
    RELOAD->setText("");
    SAVE->setIcon(QIcon(":/icons/save-solid.svg"));
    RELOAD->setIcon(QIcon(":/icons/sync-alt-solid.svg"));
    LOAD->setIcon(QIcon(":/icons/trash-restore-solid.svg"));
    APPLYER->setToolTip("Apply the selected changes");
    SAVE->setToolTip("Save the selected changes");
    RELOAD->setToolTip("Reload APT cache");
    LOAD->setToolTip("Load the saved changes");

    APPLYER->setFixedSize(BS);
    APPLYER->setText("");
    APPLYER->setIcon(QIcon(":/icons/check-solid.svg").pixmap(QSize(30,30)));

    btnL->addWidget(SAVE);
    btnL->addWidget(LOAD);
    btnL->addWidget(RELOAD);
    btnL->addWidget(APPLYER);

    btnL->setMargin(0);
    btnL->setSpacing(5);

    buttonArea->move(305, 5);
    buttonArea->setLayout(btnL);

    int finalWidth = 0;
    int i = 0;
    QList<QPushButton*> childrenining = buttonArea->findChildren<QPushButton *>();
    while (i < childrenining.length()) {
        finalWidth += childrenining.at(i)->width() + 5;
        i++;
    }

    finalWidth -= 5;

    buttonArea->setFixedWidth(finalWidth);

    /* Plz NEVER use: QApt::Backend::redo & QApt::Backend::undo,
     * It all the time fails in the current version, for the future version, we can use it, else, don't.
     * That's the reason why this feature have been removed for the moment.
     * */
    connect(SAVE, &QPushButton::clicked, &m_backend, [=]() { m_backend.saveSelections(QString("/home/" + qgetenv("USER") + "/.config/neostore/changes.ini")); });
    connect(LOAD, &QPushButton::clicked, &m_backend, [=]() { m_backend.loadSelections(QString("/home/" + qgetenv("USER") + "/.config/neostore/changes.ini")); });
    connect(RELOAD, &QPushButton::clicked, &m_backend, [=]() { m_backend.reloadCache(); pkgView->load(); });
    connect(APPLYER, &QPushButton::clicked, this, &MainView::startCommiting);
    connect(TITLEBAR, &DTitlebar::closing, this, [=]() { qApp->~DApplication(); });
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
    toolsV = new ToolsView;

    //Set up the UI.
    viewer->init(new QString("Top"));
    toolsV->load(this->runtime, m_categories);

    // Add to the layout the basic widgets.

    ui->horizontalLayout->addWidget(viewer);
    ui->horizontalLayout->addWidget(m_listing);
    ui->horizontalLayout->addWidget(pkgView);
    ui->horizontalLayout->addWidget(pageUp);
    ui->horizontalLayout->addWidget(toolsV);

    scdL->addWidget(m_categories);
    scdL->addItem(VS);
    scdL->addWidget(popuping);

    tmp->setVisible(false);

    //Add the widgets to the Duplex controler. Now fusioned with MainView.
    //Should we add a  view for the packages that will have a changement?

    addObject(toolsV);
    addObject(pageUp);
    addObject(m_listing);
    addObject(pkgView);

    // To show the default page, we load viewer in last, it make we without needing to add a new call to the Duplex controler.

    addObject(viewer);

    //Sorry for using a lot of connector systems, it's.. a little bit... ugly?

    connect(m_categories, &Categories::showCategory, viewer, &BookPage::init);
    connect(m_categories, &Categories::showCategory, this, [=] () { HSLastObject(viewer); });
    connect(m_categories, &Categories::showLister, this, [=] () { HSLastObject(m_listing); });
    connect(m_categories, &Categories::showTools, this, [=] () { HSLastObject(toolsV); });

    connect(viewer, &BookPage::openView, this, &MainView::setPV);
    connect(m_listing, SIGNAL(packageWasSelected(QString*)), this, SLOT(setPV(QString*)));
    connect(pageUp, &UpdatePage::itemWasClicked, this, &MainView::setPV);

    connect(pkgView, &PackageData::closing, [=]() { showOldObject(); });
    connect(m_categories, &Categories::callUpdatesView, this, [=]() {HSLastObject(pageUp);});
    connect(LINER, &DLineEdit::textEdited, this, [=]() { m_listing->checkByChar(new QString(LINER->text())); m_categories->selectItem(m_categories->AllApps); });
}

void MainView::loadData()
{
    ContentDownloader *starter = new ContentDownloader(this);
    packageView();
}

void MainView::startCommiting()
{
    NDeclarative *grant_declaration = new NDeclarative;

    // NDeclarative is used to declare the future changes that will be applyed and get the user grant before setting any changes.
    // List order to pass (of QApt::Package::State):
    // ToInstall, ToRemove, ToUpgrade, ToReInstall, ToDowngrade
    // It have the markedPackages int, that is the REAL number of packages that will have a change
    // Because QApt::Backend::markedPackages don't enum all of them.
    // For the moment it have some errors to show the Qstrings in the list...

    grant_declaration->setPKGList(m_backend);

    if (grant_declaration->markedPackages >= 0) {
        m_transaction = m_backend.commitChanges();
        grant_declaration->show();

        connect(grant_declaration, &NDeclarative::sessionAccepted, this, [=] () {
            // Provide proxy/locale to the transaction
            if (KProtocolManager::proxyType() == KProtocolManager::ManualProxy) {
                m_transaction->setProxy(KProtocolManager::proxyFor("http"));
            }

            m_transaction->setLocale(QLatin1String(setlocale(LC_MESSAGES, nullptr)));
            popuping->setUP(m_transaction);
            m_transaction->run();
            connect(m_transaction, &QApt::Transaction::finished, this, [=]() { m_backend.reloadCache(); m_listing->~SecondUI(); m_listing = new SecondUI(this); pageUp->~UpdatePage(); pageUp = new UpdatePage(this); });
        });
    } else {
        grant_declaration->~NDeclarative();
    }
}

void MainView::setPV(QString *data)
{
    pkgView->init(data);
    HSLastObject(pkgView);
}


void MainView::openWithFilePath(QString *path)
{
    pkgView->fileOpenedWithPath(path);
}

void MainView::openWithFilePathOnRuntime(QString path)
{
    openWithFilePath(&path);
}

QMenu* MainView::initMenu()
{
    QMenu *menu = new QMenu;
    QAction *openWith = new QAction("Open file");
    QAction *quitApp = new QAction("Exit");
    QAction *aboutApp = new QAction("About");
    QAction *settings = new QAction("Settings");

    menu->addAction(openWith);
    menu->addSeparator();
    menu->addAction(settings);
    menu->addAction(aboutApp);
    menu->addAction(quitApp);

    connect(aboutApp, &QAction::triggered, this, &MainView::openAbout);
    connect(openWith, &QAction::triggered, this, &MainView::openFX);
    connect(quitApp, &QAction::triggered, this, [=]() {qApp->~DApplication();});

    return menu;
}

void MainView::openAbout()
{
    DDialog *dial = new DDialog;
    About *about = new About;

    dial->addContent(about);
    dial->exec();
}

void MainView::openFX()
{
    QList<QString> files;

     QFileDialog dialog(this);
     dialog.setDirectory(QDir::homePath());
     dialog.setFileMode(QFileDialog::ExistingFile);
     dialog.setAcceptMode(QFileDialog::AcceptMode::AcceptOpen);

     if (dialog.exec())
         files = dialog.selectedFiles();

     QString fileListString;
     fileListString.append(files.at(0));

     qDebug() << fileListString;
     openWithFilePathOnRuntime(fileListString);
}


void MainView::addObject(QWidget *widget)
{
    objList.append(widget);
    if (isItTheFirstTime == false) {
        oldWidget->setVisible(false);
        backwardWidget = oldWidget;
    } else {
        isItTheFirstTime = false;
    }
    oldWidget = widget;
    widget->setVisible(true);
}

void MainView::HSLastObject(QWidget *widget)
{
        int i = 0;
        if (widget != nullptr && widget != oldWidget) {
            while (i < objList.length()) {
                if (widget == objList.at(i)) {
                    qDebug() << "The widget have been found.";
                    objList.at(i)->setVisible(true);
                    oldWidget->setVisible(false);
                    backwardWidget = oldWidget;
                    oldWidget = objList.at(i);
                } else {
                    objList.at(i)->setVisible(false);
                }
                i++;
            }
        }
}

void MainView::showOldObject()
{
    if (backwardWidget != nullptr || backwardWidget != oldWidget) {
        oldWidget->setVisible(false);
        backwardWidget->setVisible(true);
    } else {
        oldWidget->setVisible(false);
        objList.at(0)->setVisible(true);
    }

}
