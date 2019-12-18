#include "categories.h"
#include "ui_categories.h"

#include <QDebug>

Categories::Categories(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Categories)
{
    ui->setupUi(this);

    /*
     * We can use a QSetting to load a category list and continue to use the same system, it will offer more flexibility
    */

    ui->listWidget->addItem(new QListWidgetItem(QIcon(":/icons/star-solid.svg"), "Top Apps"));

    //Add check sys. here for categories using .ini file, schemes:
    //CV = x (Category values, the number)
    //use a loop to add categories like:
    //C0 = Games
    // and will look for the files of this directory.
    // Not implemented for the moment but should be in the future.
    ui->listWidget->addItem(new QListWidgetItem(QIcon(":/icons/box-open-solid.svg"), "All Apps"));
    ui->listWidget->addItem(new QListWidgetItem(QIcon(":/icons/arrow-alt-circle-up-solid.svg"), "Updates"));

    Tools = 0;
    int i = 0;

    while ( i < ui->listWidget->currentRow()) {
        if (ui->listWidget->item(i)->text() == QString("Updates")) {
            Updates = ui->listWidget->row(ui->listWidget->item(i));
        }
        if (ui->listWidget->item(i)->text() == QString("All Apps")) {
            AllApps = ui->listWidget->row(ui->listWidget->item(i));
        }
        if (ui->listWidget->item(i)->text() == QString("Tools")) {
            Tools = ui->listWidget->row(ui->listWidget->item(i));
        }
        i++;
    }

    // Was a labyrinth for me when used sendData(), so switched to lambda. In the future, it will go back into the sendData function.
    connect(ui->listWidget, &QListWidget::itemClicked, [=]() { QString txt = ui->listWidget->currentItem()->text();
        if (txt.contains("Top Apps") == false && txt.contains("Updates") == false && txt.contains("All Apps") == false) {
            Q_EMIT showCategory(new QString(txt));
        } else {
            if (txt.contains("Updates") == true) {
                Q_EMIT callUpdatesView();
            }
            if (txt.contains("Top Apps") == true) {
                Q_EMIT showCategory(new QString("Top"));
            }
            if (txt.contains("All Apps") == true) {
                Q_EMIT showLister();
            }
        }
    });

    this->setStyleSheet("color: #fff; font-size: 20px;");
}

Categories::~Categories()
{
    delete ui;
}

void Categories::selectItem(int i)
{
    ui->listWidget->item(i)->setSelected(true);
}
