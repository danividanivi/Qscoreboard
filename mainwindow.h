#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QtMultimedia/QSound>
#include "scoredisplay.h"
#include <QKeyEvent>
#include "shotclockdisplay.h"
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

    int get_home_timeouts(){return home_timeouts;}
    int get_away_timeouts(){return away_timeouts;}

    void add_home_timeouts(int timeouts){home_timeouts = home_timeouts + timeouts;}
    void add_away_timeouts(int timeouts){away_timeouts = away_timeouts + timeouts;}
    void set_home_timeouts(int timeouts){home_timeouts = timeouts;}
    void set_away_timeouts(int timeouts){away_timeouts = timeouts;}

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
    void on_homeGoalPlusButton_clicked();

    void on_homeGoalMinusButton_clicked();

    void on_awayGoalPlusButton_clicked();

    void on_awayGoalMinusButton_clicked();

    void on_homeTimeoutPlusButton_clicked();

    void on_homeTimeoutMinusButton_clicked();

    void on_awayTimeoutPlusButton_clicked();

    void on_awayTimeoutMinusButton_clicked();

    void on_periodPlusButton_clicked();

    void on_periodMinusButton_clicked();

    void on_shotClockStartStopButton_clicked();

    void update();
    void updateScreens();

    void on_shotClockResetButton_clicked();

    void on_hornButton_clicked();

    void on_gameClockStartStopButton_clicked();

    void on_gameClockResetButton_clicked();

    void on_addScoreScreenButton_clicked();

    void on_addShotClockScreenButton_clicked();

    void toggleShotClockVisibility();

    void on_shotClockShortResetButton_clicked();

private:
    Ui::MainWindow *ui;
    int home_goals;
    int away_goals;
    int home_timeouts;
    int away_timeouts;
    int period;

    bool time_running;
    bool allow_negative;

    QTimer *timer = new QTimer(this);
    QTimer *timerScreens = new QTimer(this);
    int shot_clock;

    ScoreDisplay *scoreWindow;
    bool scoreWindowShown;

    ShotClockDisplay *shotClockWindow;
    bool shotClockWindowShown;
    bool shotClockHidden;

    QSound shotClockSound;

    QString homeFilename;
    QString awayFilename;
};

#endif // MAINWINDOW_H
