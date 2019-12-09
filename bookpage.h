#ifndef BOOKPAGE_H
#define BOOKPAGE_H

#include "components.h"

#include <QWidget>
#include <QByteArray>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

namespace Ui {
class BookPage;
}

class BookPage : public QWidget
{
    Q_OBJECT

public:
    explicit BookPage(QWidget *parent = nullptr);
    ~BookPage();
    QString dataURL;

public: Q_SIGNALS:
    void sendData(QString *);
    void openView(QString *);

public Q_SLOTS:
    void init(QString *);
    void handleValue(QString *);

private:
    Ui::BookPage *ui;
    QNetworkAccessManager m_WebCtrl;
    QByteArray m_DownloadedData;
    Components *m_component;
};

#endif // BOOKPAGE_H
