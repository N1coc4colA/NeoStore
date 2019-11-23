#ifndef DOWNLOADAREA_H
#define DOWNLOADAREA_H

#include <QWidget>

namespace Ui {
class DownloadArea;
}

class DownloadArea : public QWidget
{
    Q_OBJECT

public:
    explicit DownloadArea(QWidget *parent = nullptr);
    ~DownloadArea();

private:
    Ui::DownloadArea *ui;
};

#endif // DOWNLOADAREA_H
