#ifndef UpdatePAGE_H
#define UpdatePAGE_H

#include "mainview.h"

#include <QWidget>

namespace Ui {
class UpdatePage;
}

class MainView;
class SpecialEdits;

class UpdatePage : public QWidget
{
    Q_OBJECT

public:
    explicit UpdatePage(MainView *parent);
    ~UpdatePage();

    QStringList *getUpdateList(QStringList *list) {
        QStringList *pkgUpdateList = new QStringList;
        int i = 0;

        while( i < list->length()) {
            //have to re-use the backend to find previous package to get a list in alphabetical order.

            if (isUpdateAvailable(PARENT->m_backend.package(list->at(i))) == true){
                pkgUpdateList->append(list->at(i));
            }
            i++;
        }
        return  pkgUpdateList;
    }

    QStringList *getInstalledList() {
        QStringList *pkgInstalledList = new QStringList;
        int i = 0;
        while (i < PARENT->m_listing->listON->length()) {

            //have to re-use the backend to find previous package to get a list in alphabetical order.
            if (PARENT->m_backend.package(PARENT->m_listing->listON->at(i))->isInstalled() == true) {
                pkgInstalledList->append(PARENT->m_listing->listON->at(i));
            }
            i++;
        }
        return pkgInstalledList;
    }

public Q_SLOTS:

Q_SIGNALS:
    void itemWasClicked(QString *);

private Q_SLOTS:
    void openIPV(QApt::PackageList *);
    void closeIPV();
    void reSendClicked(QString *);

private:
    Ui::UpdatePage *ui;
    MainView *PARENT;
};

#endif // UpdatePAGE_H
