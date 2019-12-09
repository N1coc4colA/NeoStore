#ifndef DOWNLOADAREA_H
#define DOWNLOADAREA_H

#include <QApt/Backend>
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
    void setUP(QApt::Transaction *);
    int divideby;

public Q_SLOTS:
    void progressing(int, int);
    void shadowing();

private:
    Ui::DownloadArea *ui;
};

#endif // DOWNLOADAREA_H
