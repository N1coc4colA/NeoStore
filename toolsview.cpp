#include "toolsview.h"
#include "ui_toolsview.h"

#include <dimagebutton.h>

ToolsView::ToolsView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ToolsView)
{
    ui->setupUi(this);
}

ToolsView::~ToolsView()
{
    delete ui;
}

void ToolsView::load(SpecialEdits *runtime, Categories *category)
{
    int total = 0;

    if (runtime->pkgNowBroken.isEmpty() == false) {
        ui->BP->setVisible(true);
        ui->numBP->setText(" " + QString::number(runtime->pkgNowBroken.length()) + " ");
        DImageButton *NBBtn = new DImageButton;
        NBBtn->setPixmap(QIcon(":/icons/chevron-right-solid.svg").pixmap(20));
        ui->LBP->addWidget(NBBtn);
        total = total + runtime->pkgNowBroken.length();
    } else {
        ui->BP->setVisible(false);
    }

    if (runtime->pkgNowPolicyBroken.isEmpty() == false) {
        ui->BPP->setVisible(true);
        ui->numBPP->setText(" " + QString::number(runtime->pkgNowPolicyBroken.length()) + " ");
        DImageButton *BPPBtn = new DImageButton;
        BPPBtn->setPixmap(QIcon(":/icons/chevron-right-solid.svg").pixmap(20));
        ui->LBPP->addWidget(BPPBtn);
        total = total + runtime->pkgNowPolicyBroken.length();
    } else {
        ui->BPP->setVisible(false);
    }

    if (runtime->pkgResidualConfig.isEmpty() == false) {
        ui->RCP->setVisible(true);
        ui->numRCP->setText(" " + QString::number(runtime->pkgResidualConfig.length()) + " ");
        DImageButton *BPPBtn = new DImageButton;
        BPPBtn->setPixmap(QIcon(":/icons/chevron-right-solid.svg").pixmap(20));
        ui->LRCP->addWidget(BPPBtn);
        total = total + runtime->pkgResidualConfig.length();
    } else {
        ui->RCP->setVisible(false);
    }

    if (runtime->pkgInstallPolicyBroken.isEmpty() == false) {
        ui->BIP->setVisible(true);
        ui->numBIP->setText(" " + QString::number(runtime->pkgInstallPolicyBroken.length()) + " ");
        DImageButton *BPPBtn = new DImageButton;
        BPPBtn->setPixmap(QIcon(":/icons/chevron-right-solid.svg").pixmap(20));
        ui->LBIP->addWidget(BPPBtn);
        total = total + runtime->pkgInstallPolicyBroken.length();
    } else {
        ui->BIP->setVisible(false);
    }

    if (runtime->pkgBrokenInstall.isEmpty() == false) {
        ui->BI->setVisible(true);
        ui->numBI->setText(" " + QString::number(runtime->pkgBrokenInstall.length()) + " ");
        DImageButton *BPPBtn = new DImageButton;
        BPPBtn->setPixmap(QIcon(":/icons/chevron-right-solid.svg").pixmap(20));
        ui->LBI->addWidget(BPPBtn);
        total = total + runtime->pkgBrokenInstall.length();
    } else {
        ui->BI->setVisible(false);
    }

    if (total > 10) {
       category->setAnIcon(QIcon(":/icons/numbers/more.svg"), category->Tools);
    } else {
        category->setAnIcon(QIcon(":/icons/numbers/" + QString::number(total) + ".svg"), category->Tools);
    }
}
