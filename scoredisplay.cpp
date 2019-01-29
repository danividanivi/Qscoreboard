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
    this->ui->lcdNumber->display(home);
    this->ui->lcdNumber_2->display(away);
    this->ui->lcdNumber_3->display(shot_clock);
    this->ui->lcdNumber_4->display(period);

    this->ui->main_clock_widget->set_minutes(time.minute());
    this->ui->main_clock_widget->set_seconds(time.second());
    this->ui->main_clock_widget->showTime();




    //TODO Correctly connect this widget with Main Window

}

void ScoreDisplay::random(){
    this->ui->lcdNumber->display(288);
    this->ui->lcdNumber_2->display(288);
}
