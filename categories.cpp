#include "categories.h"
#include "ui_categories.h"

Categories::Categories(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Categories)
{
    ui->setupUi(this);

    /*
     * We can use a QSetting to load a category list and continue to use the same system, it will offer more flexibility
    */

    ui->listWidget->addItem("Selection");
    ui->listWidget->addItem("All Apps");
    connect(ui->listWidget, &QListWidget::itemClicked, [=]() {sendData(new QString(ui->listWidget->currentItem()->text())); });
}

Categories::~Categories()
{
    delete ui;
}

void Categories::sendData(QString *value)
{
    QString isIt = QString("Top Apps");
    if (isIt == value) {
        value = new QString("Top");
        Q_EMIT showCategory(value);
    } else {
        Q_EMIT showLister();
    }
}
