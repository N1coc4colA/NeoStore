#include "local.h"
#include "NextUIInterface.h"

#include <QFileDialog>
#include <QString>
#include <QDebug>
#include <QFile>
#include <QSettings>
#include <QMessageBox>
#include <QtDBus/QDBusConnection>

local::local(QObject *parent) : QObject(parent)
{
    setTheme(QString("1"));
}

QString local::theTheme() const
{
    return TheTheme;
}

void local::setTheme(const QString isOn)
{
    Q_EMIT themeChanged();
}
