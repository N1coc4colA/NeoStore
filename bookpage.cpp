#include "bookpage.h"
#include "ui_bookpage.h"

#include <QFont>
#include <QDebug>
#include <QFontDatabase>
#include <QFile>

BookPage::BookPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BookPage)
{
    ui->setupUi(this);
    int db = QFontDatabase::addApplicationFont(":Staatliches-Regular.ttf");
    QString family = QFontDatabase::applicationFontFamilies(db).at(0);
    QFont bold(family);
    ui->Title->setFont(bold);
    m_component = new Components;
    ui->horizontalLayout->addWidget(m_component);
    connect(m_component, &Components::sendData, this, &BookPage::handleValue);

    qDebug() << "BookPage component initialization finished, alias viewer.";
}

BookPage::~BookPage()
{
    delete ui;
    m_component->~Components();
}

void BookPage::init(QString *SECTION)
{
    QString bckValue = nullptr;
    QString path = "/tmp/nui/";

    if (QString("Games") == SECTION) {
        ui->widget_2->setStyleSheet("background-color: #1b1b1d;");
        ui->widget_3->setStyleSheet("background-color: #1b1b1d;");
    } else {
        ui->widget_2->setStyleSheet("background-color: rgb(238, 238, 238);");
        ui->widget_3->setStyleSheet("background-color: rgb(238, 238, 238);");
    }


    ui->bckg->setStyleSheet("background-image: url(\"" + path + "Backgrounds/" + *SECTION + ".jpg\"); border-radius: 10px; background-position: center; background-origin: content;");
    ui->Title->setText(*SECTION);

    ui->Title->setStyleSheet("border-image: url(); background-image: url(); background-color: #00000000; color: white; font-size: 70px;");
    m_component->init(SECTION);

    qDebug() << "BookPage component's UI initialization finished, alias viewer.";
}

void BookPage::handleValue(QString *value)
{
    Q_EMIT openView(value);
}
