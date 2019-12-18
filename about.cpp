#include "about.h"
#include "ui_about.h"

About::About(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
    ui->QtContrib->setPixmap(QIcon(":/contrib/qt.png").pixmap(QSize(100, 100)));
    ui->KDEContrib->setPixmap(QIcon(":/contrib/kde.svg").pixmap(QSize(100, 100)));
    ui->FAContrib->setPixmap(QIcon(":/contrib/fontawesome.svg").pixmap(QSize(45, 45)));
    ui->DDEContrib->setPixmap(QIcon(":/contrib/deepin.svg").pixmap(ui->DDEContrib->size()));
    ui->LOGO->setPixmap(QIcon(":/mybg.svg").pixmap(QSize(140, 140)));

    ui->hyperlink->setText("<a href=\"https://github.com/N1coc4colA/NeoStore\" style='text-decoration: none; font-size:13px; color: #004EE5;'>Source code of the project </a>");
    ui->hyperlink->setTextFormat(Qt::RichText);
    ui->hyperlink->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->hyperlink->setOpenExternalLinks(true);
}

About::~About()
{
    delete ui;
}
