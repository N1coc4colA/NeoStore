#include "contentdownloader.h"
#include "downloadhandler.h"

#include <QDir>
#include <ddialog.h>
#include <QDebug>

DWIDGET_USE_NAMESPACE

ContentDownloader::ContentDownloader(MainView *parent)
{
    downloadDB = new QProcess;
    prevent = new Start;

    QString path = QString("/home/" + qgetenv("USER") + "/.config/neostore");
    QDir directory("/tmp/nui/NeoStore-WebContent-master");
    QDir baseDir(path);
    QFile file("/tmp/nui/master");
    QFile bases(path + "/changes.ini");

    //Checking for the file of selections (Packages to install, remove...)
    //If don't exists for the user, create a new one.
    //What happen if a package to install is not available in the APT repos and the user selects apply?
    //The app (I think) should crash.
    if (!bases.exists()) {
        QProcess basesMaker;
        if (!baseDir.exists()) {
            basesMaker.startDetached("mkdir " + path);
        }
        basesMaker.startDetached("touch " + path);
    }

    // The most important is the directory, not the .zip file.
    // We check if it exists.
    // If it don't exists, we look for the zip file (which have all the web content)
    // Else, we download it, and extract it. Note that this sh*ty program, so usefull of unzip isn't flexible anymore.
    // We need to use a .sh file to extract, else, in app, it unzips in root dir. of the app
    // And creates a segmentation fault.

    if (!directory.exists()) {
        prevent->show();

        if (!file.exists()) {

            startCommands();
            DownloadManager *handler = new DownloadManager;
            handler->append(QString("https://codeload.github.com/N1coc4colA/NeoStore-WebContent/zip/master"));
            connect(handler, &DownloadManager::statusChanged, this, &ContentDownloader::setPercentage);

        } else {

            downloadDB->startDetached("rm -r /tmp/nui/NeoStore-WebContent-master");
            qDebug() << downloadDB->readAllStandardOutput();
            setPercentage(100);

        }
    }
}

ContentDownloader::~ContentDownloader()
{
    prevent->~Start();
    downloadDB->~QProcess();
}

void ContentDownloader::closing()
{
    PARENT->setVisible(true);
    prevent->close();
    this->~ContentDownloader();
}

void ContentDownloader::setPercentage(int value)
{
    if (value >= 100) {
        QString command4 =  "/usr/share/neostore/runtime/extraction.sh";
        downloadDB->start(command4);
        qDebug() << downloadDB->readAllStandardOutput();
        prevent->close();
    } else {
        prevent->setPercentage(value);
    }
}

void ContentDownloader::startCommands()
{
    QString command = "rm -f -r /tmp/nui";
    QString command2 = "mkdir /tmp/nui";
    QString command3 = "cd /tmp/nui";

    downloadDB->startDetached(command);
    downloadDB->waitForFinished();
    qDebug() << downloadDB->readAllStandardOutput();

    downloadDB->startDetached(command2);
    downloadDB->waitForFinished();
    qDebug() << downloadDB->readAllStandardOutput();
    downloadDB->startDetached(command3);
    downloadDB->waitForFinished();
    qDebug() << downloadDB->readAllStandardOutput();
}
