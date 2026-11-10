#include "timeoffdisplay.h"
#include "ui_timeoffdisplay.h"

TimeOffDisplay::TimeOffDisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TimeOffDisplay)
{
    ui->setupUi(this);
}

TimeOffDisplay::~TimeOffDisplay()
{
    delete ui;
}

void TimeOffDisplay::updateDisplay(int seconds, bool hide){
    this->ui->shotClockDisplay->display(seconds);
    if(hide){
        this->ui->shotClockDisplay->hide();
    }
    else {
        this->ui->shotClockDisplay->show();
    }
}
