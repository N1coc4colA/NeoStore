#ifndef LOCALFILTER_H
#define LOCALFILTER_H

#include <QObject>
#include <QFutureWatcher>
#include <qapt/backend.h>
#include <QListWidget>

class LocalFilter : public QObject
{
    Q_OBJECT
public:
    explicit LocalFilter(QObject *parent = nullptr);
    ~LocalFilter();
    QVector<QString *> values;
    QApt::PackageList listing;

Q_SIGNALS:
    void dataHF();
    void replyValues(QString *);

public Q_SLOTS:
    void replyEdits();

private:
    QApt::Backend *m_backend;
    QFutureWatcher<QList<QApt::Package*> >* m_watcher;
};

#endif // LOCALFILTER_H
