#ifndef MAINVIEW_H
#define MAINVIEW_H
#include "start.h"
#include "packageview.h"
#include "bookpage.h"
#include "categories.h"
#include "secondui.h"
#include "downloadarea.h"

#include <QApt/Transaction>

#include <QDebug>
#include <DThemeManager>
#include <QSpacerItem>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QIcon>
#include <QProcess>
#include <QPushButton>
#include <DLineEdit>
#include <QWidget>
#include <DTitlebar>
#include <DBlurEffectWidget>

DWIDGET_USE_NAMESPACE

namespace Ui {
class MainView;
}

class PackageData;
class SecondUI;
class UpdatePage;
class SpecialEdits;

class MainView : public QWidget
{
    Q_OBJECT

public:
    explicit MainView(QWidget *parent = nullptr);
    ~MainView();
    QHBoxLayout *horizontalLayout;
    QApt::Backend m_backend;
    QApt::Transaction *m_transaction;
    SecondUI *m_listing;
    SpecialEdits *runtimeInfos;
    SpecialEdits *runtime;

private:
    Ui::MainView *ui;
    DTitlebar *TITLEBAR;
    QVBoxLayout *reloadedL;
    QHBoxLayout *tL;
    QVBoxLayout *scdL;
    PackageData *pkgView;
    BookPage *viewer;
    Categories *m_categories;
    DLineEdit *LINER;
    QPushButton *APPLYER;
    DownloadArea *popuping;
    UpdatePage *pageUp;

public Q_SLOTS:
    void packageView();
    void viewList();
    void loadData();
    void showListing();
    void setPV(QString *);
    void startCommiting();
};

class SpecialEdits : QObject
{
    Q_OBJECT

public:
    static SpecialEdits *runtime()
    {
        return new SpecialEdits;
    }

    //Pkg Updates components.

    QStringList PkgUpdates;

    QStringList *getUpdateList() {
        return &PkgUpdates;
    }

    static bool packageNameLessThan(QString p1, QString p2)
    {
         return p1 < p2;
    }

    void UpdateChecking(QStringList *list)
    {
        PkgUpdates = *list;
    }

    static QStringList *sortPackages(QStringList *list)
    {
        std::sort(list->begin(), list->end(), packageNameLessThan);
        return list;
    }

    //Use some schemes previously used for updates but for Pkg Installed.

    void InstalledChecking(QStringList *list)
    {
        PkgInstalled = *list;
    }

    QStringList PkgInstalled;

    QStringList *getInstalledList() {
        return &PkgInstalled;
    }
};

static bool isUpdateAvailable(QApt::Package *pkg)
{
     if (pkg->availableVersion() > pkg->version()) {
         return true;
     } else {
         return false;
     }
}

#endif // MAINVIEW_H
