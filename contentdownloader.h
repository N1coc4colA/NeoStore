#ifndef CONTENTDOWNLOADER_H
#define CONTENTDOWNLOADER_H
#include "start.h"
#include "mainview.h"
#include <qdebug.h>

#include <QProcess>
#include <QObject>

class ContentDownloader : public QObject
{
    Q_OBJECT
public:
    explicit ContentDownloader(MainView *parent);
    ~ContentDownloader();
    Start *prevent;
    QProcess *downloadDB;
    MainView *PARENT;
    void startCommands();

public Q_SLOTS:
    void closing();
    void setPercentage(int);
};

#endif // CONTENTDOWNLOADER_H
