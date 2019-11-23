#include "downloadarea.h"
#include "ui_downloadarea.h"

DownloadArea::DownloadArea(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DownloadArea)
{
    ui->setupUi(this);
}

DownloadArea::~DownloadArea()
{
    delete ui;
}
