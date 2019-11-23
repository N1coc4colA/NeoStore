#include "appcomponent.h"
#include "ui_appcomponent.h"

#include <DThemeManager>

AppComponent::AppComponent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AppComponent)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(sendData()));
}

AppComponent::~AppComponent()
{
    delete ui;
}

void AppComponent::sendData()
{
    Q_EMIT objectClicked(AppName);
}

void AppComponent::init(QString *NAME)
{
    ui->AppName->setText(*NAME);
    AppName = NAME;
    Dtk::Widget::DThemeManager::instance()->setTheme("dlight");
}
