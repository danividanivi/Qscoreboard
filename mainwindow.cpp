#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMultimedia/QMediaPlayer>
#include "scoredisplay.h"
#include "timeoffdisplay.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    home_goals=0;
    away_goals=0;
    home_timeoff=1;
    away_timeoff=1;
    period=1;
    set_time_running(false);
    allow_negative = false;


    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    ui->setupUi(this);
    set_shot_clock(ui->lineEdit->text().toInt());


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    add_home_goals(+1);
    ui->lcdNumber->display(get_home_goals());
}

void MainWindow::on_pushButton_2_clicked()
{
    if(get_home_goals()>0 || allow_negative==true){
            add_home_goals(-1);
    }

    ui->lcdNumber->display(get_home_goals());
}

void MainWindow::on_pushButton_3_clicked()
{
    add_away_goals(+1);
    ui->lcdNumber_2->display(get_away_goals());
}

void MainWindow::on_pushButton_4_clicked()
{
    if(get_away_goals()>0 || allow_negative==true){
    add_away_goals(-1);
    }
        ui->lcdNumber_2->display(get_away_goals());
}

void MainWindow::on_pushButton_7_clicked()
{
    add_home_timeoff(+1);
    ui->lcdNumber_6->display(get_home_timeoff());
}

void MainWindow::on_pushButton_8_clicked()
{
    if(get_home_timeoff()>0 || allow_negative==true){
        add_home_timeoff(-1);
    }
    ui->lcdNumber_6->display(get_home_timeoff());
}

void MainWindow::on_pushButton_9_clicked()
{

    add_away_timeoff(+1);


    ui->lcdNumber_7->display(get_away_timeoff());
}

void MainWindow::on_pushButton_10_clicked()
{
    if(get_away_timeoff()>0 || allow_negative==true){
            add_away_timeoff(-1);
    }

    ui->lcdNumber_7->display(get_away_timeoff());
}

void MainWindow::on_pushButton_6_clicked()
{
    add_period(+1);
    set_home_timeoff(1);
    set_away_timeoff(1);
    ui->lcdNumber_4->display(get_period());
    ui->lcdNumber_6->display(get_home_timeoff());
    ui->lcdNumber_7->display(get_away_timeoff());
}

void MainWindow::on_pushButton_5_clicked()
{
    if(get_period()>0 || allow_negative == true){
        add_period(-1);
    }

    ui->lcdNumber_4->display(get_period());
}

void MainWindow::on_pushButton_11_clicked()
{
    //If it is stopped, start. If it is running stop it.
    if(time_running)
    {
        timer->stop();
        time_running=false;
    }
    else {
        timer->start(1000);
        time_running=true;

    }
}

void MainWindow::update()
{

    if(ui->main_clock_widget->is_playing()){
        ui->pushButton_11->setEnabled(true);
        if(get_shot_clock()>0 || allow_negative==true){
                add_shot_clock(-1);
                if(get_shot_clock()==0 ){
                        QSound::play(":/sound/sound/airhorn.wav");
                }
        }
    }




    ui->lcdNumber_3->display(get_shot_clock());
}

void MainWindow::on_pushButton_12_clicked()
{
    set_shot_clock(ui->lineEdit->text().toInt());
    ui->lcdNumber_3->display(get_shot_clock());
}

void MainWindow::on_pushButton_15_clicked()
{
    QSound::play(":/sound/sound/airhorn.wav");
}

void MainWindow::on_pushButton_14_clicked()
{
    //Main clock
    ui->main_clock_widget->start_stop();
    ui->pushButton_11->setEnabled(false);



    //Timeoff clock is synchronized with main clock
    //If it is stopped, start. If it is running stop it.
    if(get_time_running())
    {
        timer->stop();
        set_time_running(false);

    }
    else {
        timer->start(1000);
        set_time_running(true);

    }

}

void MainWindow::on_pushButton_13_clicked()
{
    ui->main_clock_widget->set_minutes(ui->lineEdit_2->text().toInt());
    ui->main_clock_widget->set_seconds(ui->lineEdit_3->text().toInt());
    ui->main_clock_widget->showTime();
}

void MainWindow::on_pushButton_16_clicked()
{
    ScoreDisplay *s = new ScoreDisplay();
    s->show();
}

void MainWindow::on_pushButton_17_clicked()
{
    TimeOffDisplay *t = new TimeOffDisplay();
    t->show();
}
