#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMultimedia/QMediaPlayer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    home_goals=0;
    away_goals=0;
    home_timeoff=1;
    away_timeoff=1;
    period=1;
    time_running = false;


    //shot_clock = ui->lineEdit->text().toInt();
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
    add_home_goals(-1);
    ui->lcdNumber->display(get_home_goals());
}

void MainWindow::on_pushButton_3_clicked()
{
    add_away_goals(+1);
    ui->lcdNumber_2->display(get_away_goals());
}

void MainWindow::on_pushButton_4_clicked()
{
    add_away_goals(-1);
    ui->lcdNumber_2->display(get_away_goals());
}

void MainWindow::on_pushButton_7_clicked()
{
    add_home_timeoff(+1);
    ui->lcdNumber_6->display(get_home_timeoff());
}

void MainWindow::on_pushButton_8_clicked()
{
    add_home_timeoff(-1);
    ui->lcdNumber_6->display(get_home_timeoff());
}

void MainWindow::on_pushButton_9_clicked()
{
    add_away_timeoff(+1);
    ui->lcdNumber_7->display(get_away_timeoff());
}

void MainWindow::on_pushButton_10_clicked()
{
    add_away_timeoff(-1);
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
    add_period(-1);
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
    add_shot_clock(-1);
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

}
