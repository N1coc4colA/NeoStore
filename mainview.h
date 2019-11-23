#ifndef MAINVIEW_H
#define MAINVIEW_H
#include "start.h"
#include "packageview.h"
#include "bookpage.h"
#include "categories.h"
#include "secondui.h"

#include <QApt/Transaction>

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

class MainView : public QWidget
{
    Q_OBJECT

public:
    explicit MainView(QWidget *parent = nullptr);
    ~MainView();
    QHBoxLayout *horizontalLayout;
    QApt::Backend m_backend;
    QApt::Transaction *m_transaction;

private:
    Ui::MainView *ui;
    DTitlebar *TITLEBAR;
    QVBoxLayout *reloadedL;
    QHBoxLayout *tL;
    QVBoxLayout *scdL;
    PackageData *pkgView;
    BookPage *viewer;
    Categories *m_categories;
    SecondUI *m_listing;
    DLineEdit *LINER;
    QPushButton *APPLYER;

public Q_SLOTS:
    void packageView();
    void viewList();
    void loadData();
    void showListing();
    void setPV(QString *);
    void startCommiting();

    QApt::Backend *getTop(MainView *parent)
    {
        return &parent->m_backend;
    }
};

#endif // MAINVIEW_H
