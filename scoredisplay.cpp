#include "scoredisplay.h"
#include "ui_scoredisplay.h"

ScoreDisplay::ScoreDisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScoreDisplay)
{
    ui->setupUi(this);
}

ScoreDisplay::~ScoreDisplay()
{
    delete ui;
}

void ScoreDisplay::updateDisplay(int home, int away, int shot_clock, int period, QTime time){
    this->ui->homeGoalsDisplay->display(home);
    this->ui->awayGoalsDisplay->display(away);
    this->ui->shotClockDisplay->display(shot_clock);
    this->ui->periodDisplay->display(period);

    this->ui->main_clock_widget->set_minutes(time.minute());
    this->ui->main_clock_widget->set_seconds(time.second());
    this->ui->main_clock_widget->showTime();
}

void ScoreDisplay::changeHomePicture(QString fileName)
{
    if (!fileName.isEmpty()){
        ui->homeLogoLabel->setPixmap(fileName);
    }
}

void ScoreDisplay::changeAwayPicture(QString fileName)
{
    if (!fileName.isEmpty()){
        ui->awayLogoLabel->setPixmap(fileName);
    }
}
