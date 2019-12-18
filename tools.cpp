#include "tools.h"
#include "ui_tools.h"

Tools::Tools(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tools)
{
    ui->setupUi(this);
}

Tools::~Tools()
{
    delete ui;
}
