#include "downloadpage.h"
#include "ui_downloadpage.h"

DownloadPage::DownloadPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DownloadPage)
{
    ui->setupUi(this);
}

DownloadPage::~DownloadPage()
{
    delete ui;
}
