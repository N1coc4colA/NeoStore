#ifndef DOWNLOADPAGE_H
#define DOWNLOADPAGE_H

#include <QWidget>

namespace Ui {
class DownloadPage;
}

class DownloadPage : public QWidget
{
    Q_OBJECT

public:
    explicit DownloadPage(QWidget *parent = nullptr);
    ~DownloadPage();

private:
    Ui::DownloadPage *ui;
};

#endif // DOWNLOADPAGE_H
