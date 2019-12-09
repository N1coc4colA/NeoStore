#include "downloadarea.h"
#include "ui_downloadarea.h"

#include <QApt/Transaction>

DownloadArea::DownloadArea(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DownloadArea)
{
    this->setStyleSheet("background-color: #0000006b");
    ui->setupUi(this);
    divideby = 1;
    ui->widget->setVisible(false);
    ui->widget_2->setVisible(true);
}

DownloadArea::~DownloadArea()
{
    delete ui;
}

void DownloadArea::setUP(QApt::Transaction *m_trans)
{
    ui->widget_2->setVisible(false);
    ui->widget->setVisible(true);
    connect(m_trans, &QApt::Transaction::downloadSpeedChanged, this, [=] () { ui->dinteger->setText(QString::number(m_trans->downloadSpeed())); });
    connect(m_trans, &QApt::Transaction::progressChanged, this, [=] () { progressing(m_trans->downloadProgress().progress(), m_trans->progress()); });
    m_trans->downloadSpeed();

    connect(m_trans, &QApt::Transaction::finished, this, &DownloadArea::shadowing);
}

void DownloadArea::progressing(int value, int final)
{
    int max = 100;

    if (value >= max ) {
        divideby = 2;
        ui->status->setText("Installing");
        ui->progressBar->setValue(final / divideby);
        ui->label_4->setText("%");
        ui->dinteger->setText(QString::number(final / divideby));
    } else {
        divideby = 1;
        ui->status->setText("Downloading");
        ui->label_4->setText("b/s");
        ui->progressBar->setValue(value);
    }
}

void DownloadArea::shadowing()
{
    ui->widget_2->setVisible(true);
    ui->widget->setVisible(false);
}
