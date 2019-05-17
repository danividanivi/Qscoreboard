#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QtMultimedia/QSound>
#include "scoredisplay.h"
#include <QKeyEvent>
#include <QDebug>
#include "timeoffdisplay.h"
#include <QDesktopWidget>
#include <QFileDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int get_period(){return period;}
    void add_period(int p){period = period + p;}

    int get_home_goals(){return home_goals;}
    int get_away_goals(){return away_goals;}

    void add_home_goals(int goals){home_goals = home_goals + goals;}
    void add_away_goals(int goals){away_goals = away_goals + goals;}

    int get_home_timeoff(){return home_timeoff;}
    int get_away_timeoff(){return away_timeoff;}

    void add_home_timeoff(int timeoff){home_timeoff = home_timeoff + timeoff;}
    void add_away_timeoff(int timeoff){away_timeoff = away_timeoff + timeoff;}
    void set_home_timeoff(int timeoff){home_timeoff = timeoff;}
    void set_away_timeoff(int timeoff){away_timeoff = timeoff;}

    void add_shot_clock(int time){shot_clock = shot_clock + time;}
    void set_shot_clock(int time){shot_clock = time;}
    int get_shot_clock(){return shot_clock;}

    void set_time_running(bool run){time_running = run;}
    bool get_time_running(){return time_running;}

public slots:
    void changeHomePicture();
    void changeAwayPicture();

protected:
    void keyPressEvent(QKeyEvent *);

signals:
    void homePictureChanged(QString);
    void awayPictureChanged(QString);


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_11_clicked();

    void update();
    void updateScreens();


    void on_pushButton_12_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void hideTimeOff();



private:
    Ui::MainWindow *ui;
    int home_goals;
    int away_goals;
    int home_timeoff;
    int away_timeoff;
    int period;

    bool time_running;
    bool allow_negative;

    QTimer *timer = new QTimer(this);
    QTimer *timerScreens = new QTimer(this);
    int shot_clock;

    ScoreDisplay *s;
    bool secondScreen;

    TimeOffDisplay *t;
    bool timeoffScreen;
    bool timeoffHidden;
    bool thirdScreen;

    QSound timeOffSound;

    QString homeFilename;
    QString awayFilename;

};

#endif // MAINWINDOW_H
