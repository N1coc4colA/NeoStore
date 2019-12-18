#include "appcomponent.h"
#include "ui_appcomponent.h"

#include <DThemeManager>
#include <QLabel>

AppComponent::AppComponent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AppComponent)
{
    AppName = new QString("");
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, [=]() {Q_EMIT objectClicked(AppName);} );
    dark(false);
}

AppComponent::~AppComponent()
{
    delete ui;
    AppName->~QString();
}

void AppComponent::sendData()
{
    Q_EMIT objectClicked(AppName);
}

void AppComponent::init(QString *NAME, QString *RN)
{
    ui->label->setPixmap(QIcon::fromTheme(*RN).pixmap(40, QIcon::Mode::Normal));
    ui->AppName->setText(*NAME);
    AppName = RN;
    dark(false);
    Dtk::Widget::DThemeManager::instance()->setTheme("light");
    Dtk::Widget::DThemeManager::instance()->setTheme(ui->pushButton, "light");
}

void AppComponent::dark(bool value)
{
    if (value == false) {
        this->setStyleSheet("#AppComponent{color: #000; background:#fff;}");
    } else {
        this->setStyleSheet("#AppComponent{color: #fff; background:#e4e4e4;}");
    }
    this->setStyleSheet("border-radius: 5px;");
}
