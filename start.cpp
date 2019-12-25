#include "start.h"
#include "ui_start.h"

Start::Start(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Start)
{
    ui->setupUi(this);
    this->setWindowTitle("Loading Web Content...");
}

Start::~Start()
{
    delete ui;
}

void Start::setPercentage(int value)
{
    ui->progressBar->setValue(value);
}
