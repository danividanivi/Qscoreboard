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
    this->ui->lcdNumber->display(seconds);
    if(hide){
        this->ui->lcdNumber->hide();
    }
    else {
        this->ui->lcdNumber->show();
    }

}
