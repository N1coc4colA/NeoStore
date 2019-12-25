#include "components.h"
#include "ui_components.h"
#include "flowlayout.h"

#include <QSettings>
#include <QDebug>
#include <QFile>

Components::Components(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Components)
{
    old_length = 0;
    ui->setupUi(this);

    FlowLayout *layering = new FlowLayout;

    app1 = new AppComponent;
    app2 = new AppComponent;
    app3 = new AppComponent;
    app4 = new AppComponent;
    app5 = new AppComponent;
    app6 = new AppComponent;
    app7 = new AppComponent;
    app8 = new AppComponent;

    layering->addWidget(app1);
    layering->addWidget(app2);
    layering->addWidget(app3);
    layering->addWidget(app4);
    layering->addWidget(app5);
    layering->addWidget(app6);
    layering->addWidget(app7);
    layering->addWidget(app8);

    connect(app1, &AppComponent::objectClicked, this, &Components::reUploadData);
    connect(app2, &AppComponent::objectClicked, this, &Components::reUploadData);
    connect(app3, &AppComponent::objectClicked, this, &Components::reUploadData);
    connect(app4, &AppComponent::objectClicked, this, &Components::reUploadData);
    connect(app5, &AppComponent::objectClicked, this, &Components::reUploadData);
    connect(app6, &AppComponent::objectClicked, this, &Components::reUploadData);
    connect(app7, &AppComponent::objectClicked, this, &Components::reUploadData);
    connect(app8, &AppComponent::objectClicked, this, &Components::reUploadData);

    layering->setMinimumSpacing(10, 20);
    ui->MLL->addLayout(layering);
    this->setStyleSheet("background-color: #fff");
}

Components::~Components()
{
    delete ui;
    app1->~AppComponent();
    app2->~AppComponent();
    app3->~AppComponent();
    app4->~AppComponent();
    app5->~AppComponent();
    app6->~AppComponent();
    app7->~AppComponent();
    app8->~AppComponent();
    old_sec.~QString();
}

void Components::init(QString * SECTION)
{
    QString path = "/tmp/nui/NeoStore-WebContent-master/" + *SECTION + "/apps.ini";
    QFile file(path);

    if (!file.open(QFile::ReadWrite | QFile::Text)) {
        qDebug() << "Warning! Apps of the category" + *SECTION + " cannot be loaded...";
        qDebug() << "The path used was: " + path;
    } else {
        QSettings settings(path, QSettings::NativeFormat);
        app1->init(new QString(settings.value("0").toString()), new QString(settings.value("RN0").toString()));
        app2->init(new QString(settings.value("1").toString()), new QString(settings.value("RN1").toString()));
        app3->init(new QString(settings.value("2").toString()), new QString(settings.value("RN2").toString()));
        app4->init(new QString(settings.value("3").toString()), new QString(settings.value("RN3").toString()));
        app5->init(new QString(settings.value("4").toString()), new QString(settings.value("RN4").toString()));
        app6->init(new QString(settings.value("5").toString()), new QString(settings.value("RN5").toString()));
        app7->init(new QString(settings.value("6").toString()), new QString(settings.value("RN6").toString()));
        app8->init(new QString(settings.value("7").toString()), new QString(settings.value("RN7").toString()));
        settings.setValue("0", "Deepin File Manager");
        settings.setValue("RN0", "dde-file-manager");
    }


    if (SECTION == QString("Games")) {
        app1->dark(true);
        app2->dark(true);
        app3->dark(true);
        app4->dark(true);
        app5->dark(true);
        app6->dark(true);
        app7->dark(true);
        app8->dark(true);
    }

    old_sec = *SECTION;
}

void Components::reUploadData(QString *value)
{
    Q_EMIT sendData(value);
}
