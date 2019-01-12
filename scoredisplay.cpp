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

void ScoreDisplay::updateDisplay(int home, int away){
    this->ui->lcdNumber->display(home);
    this->ui->lcdNumber_2->display(away);
    //TODO Correctly connect this widget with Main Window

}
