#ifndef MAINVIEW_H
#define MAINVIEW_H
#include "start.h"
#include "packageview.h"
#include "bookpage.h"
#include "categories.h"
#include "secondui.h"
#include "downloadarea.h"
#include "toolsview.h"
#include "dtitlebar.h"

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
#include <DBlurEffectWidget>

DWIDGET_USE_NAMESPACE

namespace Ui {
class MainView;
}

class PackageData;
class SecondUI;
class UpdatePage;
class SpecialEdits;
class ToolsView;

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
    Categories *m_categories;
    QMenu *initMenu();

private:
    Ui::MainView *ui;
    DTitlebar *TITLEBAR;

    QVBoxLayout *reloadedL;
    QHBoxLayout *tL;
    QVBoxLayout *scdL;

    PackageData *pkgView;
    BookPage *viewer;
    UpdatePage *pageUp;
    DownloadArea *popuping;
    ToolsView *toolsV;

    QLineEdit *LINER;

    QPushButton *APPLYER;
    QList<QWidget *> objList;
    QWidget *oldWidget;
    QWidget *backwardWidget;
    bool isItTheFirstTime = true;

public Q_SLOTS:
    void packageView();
    void loadData();
    void openAbout();
    void openFX();
    void setPV(QString *);
    void startCommiting();
    void openWithFilePath(QString*);
    void openWithFilePathOnRuntime(QString);
    void HSLastObject(QWidget *);
    void addObject(QWidget *);
    void showOldObject();
};

class SpecialEdits : public QObject
{
    Q_OBJECT

public:
    static SpecialEdits *runtime()
    {
        return new SpecialEdits;
    }

    static bool packageNameLessThan(QString p1, QString p2)
    {
         return p1 < p2;
    }

    static QStringList *sortPackages(QStringList *list)
    {
        std::sort(list->begin(), list->end(), packageNameLessThan);
        return list;
    }

    QStringList pkgToUpdate;
    QStringList pkgToInstall;
    QStringList pkgToRemove;
    QStringList pkgToReInstall;
    QStringList pkgToDowngrade;

    QStringList pkgBrokenInstall;
    QStringList pkgNowBroken;
    QStringList pkgResidualConfig;
    QStringList pkgNowPolicyBroken;
    QStringList pkgInstallPolicyBroken;

    bool checkIfToInstall(QString *value)
    {
        int i = 0;
        while (i<pkgToInstall.length()) {
            if (pkgToInstall.at(i) == value) {
                return true;
            }
        }
        return false;
    }

    bool checkIfToReInstall(QString *value)
    {
        int i = 0;
        while (i<pkgToReInstall.length()) {
            if (pkgToReInstall.at(i) == value) {
                return true;
            }
        }
        return false;
    }

    bool checkIfToRemove(QString *value)
    {
        int i = 0;
        while (i<pkgToRemove.length()) {
            if (pkgToRemove.at(i) == value) {
                return true;
            }
        }
        return false;
    }

    bool checkIfToUpdate(QString *value)
    {
        int i = 0;
        while (i<pkgToUpdate.length()) {
            if (pkgToUpdate.at(i) == value) {
                return true;
            }
        }
        return false;
    }

    bool checkIfToDowngrade(QString *value)
    {
        int i = 0;
        while (i<pkgToDowngrade.length()) {
            if (pkgToDowngrade.at(i) == value) {
                return true;
            }
        }
        return false;
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
