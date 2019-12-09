#include "trying.h"
#include "ui_trying.h"

Trying::Trying(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Trying)
{
    ui->setupUi(this);
}

Trying::~Trying()
{
    delete ui;
}
