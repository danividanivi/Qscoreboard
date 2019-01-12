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
