#include "shotclockdisplay.h"
#include "ui_shotclockdisplay.h"

ShotClockDisplay::ShotClockDisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShotClockDisplay)
{
    ui->setupUi(this);
}

ShotClockDisplay::~ShotClockDisplay()
{
    delete ui;
}

void ShotClockDisplay::updateDisplay(int seconds, bool hide){
    this->ui->shotClockDisplay->display(seconds);
    if(hide){
        this->ui->shotClockDisplay->hide();
    }
    else {
        this->ui->shotClockDisplay->show();
    }
}
