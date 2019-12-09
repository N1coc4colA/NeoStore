#include "lookupobj.h"
#include "ui_lookupobj.h"

#include <QFile>
#include <QIcon>

LookUpObj::LookUpObj(QString *name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LookUpObj)
{
    ui->setupUi(this);
    QIcon::Mode mode = QIcon::Mode::Normal;
    QIcon::State state = QIcon::State::Off;
    QSize *sizing = new QSize(170, 170);
    QString *path = new QString("/usr/share/icons/Papirus/64x64/apps/");
    QString truePath(QString::fromStdString(path->toStdString() + QString(*name).toStdString() + QString(".svg").toStdString()));
    QFile appfile(truePath);

    if (appfile.exists() == true) {
        ui->Icon->setPixmap(QIcon::fromTheme(*name).pixmap(*sizing, mode, state));
    } else {
        QFile secondOP(QString("/usr/share/icons/deepin/apps/128") + QString(*name) + QString(".svg"));
        if (secondOP.exists() == true) {
            ui->Icon->setPixmap(QIcon::fromTheme(*name).pixmap(*sizing, mode, state));
        } else {
            ui->Icon->setPixmap(QIcon::fromTheme("muon").pixmap(*sizing, mode, state));
        }
    }
    ui->label->setText(*name);

    QWidget *LAYER = new QWidget(this);
    LAYER->setStyleSheet("background-color: #00000000;");
    LAYER->setFixedSize(this->width(), this->height());
    connect(LAYER, SIGNAL(mouseReleaseEvent()), this, SLOT(clicker(name)));
}

LookUpObj::~LookUpObj()
{
    delete ui;
}
