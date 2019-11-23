#include "mainview.h"
#include <QSettings>
#include <DApplication>

int main(int argc, char *argv[])
{
    Dtk::Widget::DApplication::loadDXcbPlugin();
      QApplication a(argc, argv);

      a.setApplicationName("NeoStore");
      a.setOrganizationName(QString(QObject::tr("The Comunity")));
      a.setApplicationName("NeoStore");
      a.setApplicationVersion("1.β");
      a.setAttribute(Qt::AA_UseHighDpiPixmaps);
      a.setApplicationDisplayName(QObject::tr("NeoStore"));
      a.setWindowIcon(QIcon::fromTheme("ao-app"));

    MainView w;
    w.setMinimumSize(800, 600);
    w.setGeometry(100, 100, 1000, 800);
    w.show();

    return a.exec();
}
