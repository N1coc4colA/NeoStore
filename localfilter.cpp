#include "localfilter.h"

#include <QtConcurrent/QtConcurrent>

bool packageNameLessThan(QApt::Package *p1, QApt::Package *p2)
{
     return p1->name() < p2->name();
}

QApt::PackageList sortPackages(QApt::PackageList list)
{
    std::sort(list.begin(), list.end(), packageNameLessThan);
    return list;
}

LocalFilter::LocalFilter(QObject *parent) : QObject(parent)
{
    m_backend = new QApt::Backend;
     m_backend->init();
     QApt::PackageList packageList = m_backend->availablePackages();

     qDebug() << packageList.length();

     m_watcher = new QFutureWatcher<QList<QApt::Package*> >(this);
     QFuture<QList<QApt::Package*> > future = QtConcurrent::run(sortPackages, packageList);
     m_watcher->setFuture(future);

     listing = m_watcher->result();

     replyEdits();
}

LocalFilter::~LocalFilter()
{
    m_backend->~Backend();
    m_watcher->~QFutureWatcher();
    listing.~QList();
    values.~QVector();
}

void LocalFilter::replyEdits()
{
    int i = 0;
    while ( i < listing.length() ) {
        // There is a statement ERROR IF you simply use ONE CONDITION with ISGARBAGE.
        // To remove the useless packages, we chack if they are compatible with the CPU native Architecture.
        if (listing.at(i)->IsGarbage == QApt::Package::State::IsGarbage && listing.at(i)->isForeignArch()) {} else {
            replyValues(new QString(listing.at(i)->name()));
        }
        i++;
    }
    this->~LocalFilter();
}
