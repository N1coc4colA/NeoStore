#ifndef LOCAL_H
#define LOCAL_H

#include <QObject>
#include <QString>
#include <QSet>
#include <QDebug>
#include <QFile>

class local : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString TheTheme READ theTheme WRITE setTheme NOTIFY themeChanged)
public:
    explicit local(QObject *parent = nullptr);
    QString theTheme() const;
    void setTheme(const QString isOn);

Q_SIGNALS:
    void themeChanged(QString);

public:
    QString TheTheme;
    QString m_settings;
    QString pathValue;
    QFile *file;

};

#endif // LOCAL_H
