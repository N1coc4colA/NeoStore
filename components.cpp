#include "components.h"
#include "ui_components.h"

#include <QSettings>
#include <QDebug>
#include <QFile>

Components::Components(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Components)
{
    old_length = 0;
    ui->setupUi(this);

    app1 = new AppComponent;
    app2 = new AppComponent;
    app3 = new AppComponent;
    app4 = new AppComponent;
    app5 = new AppComponent;
    app6 = new AppComponent;
    app7 = new AppComponent;
    app8 = new AppComponent;

    ui->gridLayout->addWidget(app1, 0, 1);
    ui->gridLayout->addWidget(app2, 0, 2);
    ui->gridLayout->addWidget(app3, 0, 3);
    ui->gridLayout->addWidget(app4, 0, 4);
    ui->gridLayout->addWidget(app5, 1, 1);
    ui->gridLayout->addWidget(app6, 1, 2);
    ui->gridLayout->addWidget(app7, 1, 3);
    ui->gridLayout->addWidget(app8, 1, 4);
}

Components::~Components()
{
    delete ui;
}

void Components::init(QString * SECTION)
{
    int key = 0;
    int value = 0;

    QString path = "/tmp/nui/" + *SECTION + "/apps.ini";
    qDebug() << path;

    QFile file("/tmp/nui/" + *SECTION + "/apps.ini");

    if (!file.open(QFile::ReadWrite | QFile::Text)) {
        qDebug() << "Warning! Apps of the category" + *SECTION + " cannot be loaded...";
        qDebug() << "The path used was: " + path;
    } else {
        QSettings settings(path, QSettings::NativeFormat);
        app1->init(new QString(settings.value("0").toString()));
        app2->init(new QString(settings.value("1").toString()));
        app3->init(new QString(settings.value("2").toString()));
        app4->init(new QString(settings.value("3").toString()));
        app5->init(new QString(settings.value("4").toString()));
        app6->init(new QString(settings.value("5").toString()));
        app7->init(new QString(settings.value("6").toString()));
        app8->init(new QString(settings.value("7").toString()));
    }

    if (SECTION == QString("Games")) {
        app1->setStyleSheet("color: #fff;");
        app2->setStyleSheet("color: #fff;");
        app3->setStyleSheet("color: #fff;");
        app4->setStyleSheet("color: #fff;");
        app5->setStyleSheet("color: #fff;");
        app6->setStyleSheet("color: #fff;");
        app7->setStyleSheet("color: #fff;");
        app8->setStyleSheet("color: #fff;");
    } else {
        app1->setStyleSheet("color: #000;");
        app2->setStyleSheet("color: #000;");
        app3->setStyleSheet("color: #000;");
        app4->setStyleSheet("color: #000;");
        app5->setStyleSheet("color: #000;");
        app6->setStyleSheet("color: #000;");
        app7->setStyleSheet("color: #000;");
        app8->setStyleSheet("color: #000;");
    }

    old_sec = *SECTION;
}
