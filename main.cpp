#include "mainview.h"
#include "NextUIInterface.h"

#include <QSettings>
#include <QDBusConnection>
#include <QCommandLineParser>
#include <DApplication>
#include <QCommandLineOption>

int main(int argc, char *argv[])
{
    Dtk::Widget::DApplication::loadDXcbPlugin();
    QApplication a(argc, argv);
    a.setApplicationName("NeoStore");
    a.setOrganizationName(QString(QObject::tr("The Comunity")));
    a.setApplicationName("NeoStore");
    a.setApplicationVersion("0.5.4");
    a.setAttribute(Qt::AA_UseHighDpiPixmaps);
    a.setApplicationDisplayName(QObject::tr("NeoStore"));
    a.setWindowIcon(QIcon(":/mybg.svg"));
    a.quitOnLastWindowClosed();

    QCommandLineParser parser;
    parser.addHelpOption();
    parser.addVersionOption();
    parser.applicationDescription();

    QCommandLineOption OP("f", "file", "Option to openn a deb file with this app, ONE BY ONE, NeoStore don't supports anymore multiple files opening./n use it with: [-file-open/-file-open-deb] (url:)<file path> .");

    parser.addOption(OP);
    parser.process(a);

    QString path;

    MainView w;
    w.setMinimumSize(800, 600);
    w.setGeometry(100, 100, 1000, 800);

    const QStringList args = parser.positionalArguments();

        if (parser.isSet(OP) == true) {
            qDebug() << "is it: " << parser.value(OP);
            if (args.length() == 0) {
                path = parser.value(OP);
                    if ((path != QString("") || path != QString("url:")) && path.contains("/")) {
                        qDebug() << path.remove("url:");
                        w.openWithFilePath(&path);
                }
            }
        }

    w.show();
    return a.exec();
}
