#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "scoredisplay.h"
#include "shotclockdisplay.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    shotClockSound(":/sound/sound/airhorn.wav")
{
    home_goals=0;
    away_goals=0;
    home_timeouts=1;
    away_timeouts=1;
    period=1;
    set_time_running(false);
    allow_negative = false;
    scoreWindowShown = false;
    shotClockWindowShown = false;
    shotClockHidden = false;

    homeFilename = ":/img/img/cwl500.png";
    awayFilename = ":/img/img/cwl500.png";

    //update secondary sreens (if they exist) every 1 millisecond
    timerScreens->start(1);

    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    ui->setupUi(this);
    set_shot_clock(ui->shotClockInput->text().toInt());
    connect(timerScreens, SIGNAL(timeout()), this, SLOT(updateScreens()));

    connect(ui->homeLogoLabel, SIGNAL(clicked()), this, SLOT(changeHomePicture()));
    connect(ui->awayLogoLabel, SIGNAL(clicked()), this, SLOT(changeAwayPicture()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_homeGoalPlusButton_clicked()
{
    add_home_goals(+1);
    ui->homeGoalsDisplay->display(get_home_goals());
}

void MainWindow::on_homeGoalMinusButton_clicked()
{
    if(get_home_goals()>0 || allow_negative==true){
        add_home_goals(-1);
    }

    ui->homeGoalsDisplay->display(get_home_goals());
}

void MainWindow::on_awayGoalPlusButton_clicked()
{
    add_away_goals(+1);
    ui->awayGoalsDisplay->display(get_away_goals());
}

void MainWindow::on_awayGoalMinusButton_clicked()
{
    if(get_away_goals()>0 || allow_negative==true){
        add_away_goals(-1);
    }
    ui->awayGoalsDisplay->display(get_away_goals());
}

void MainWindow::on_homeTimeoutPlusButton_clicked()
{
    add_home_timeouts(+1);
    ui->homeTimeoutsDisplay->display(get_home_timeouts());
}

void MainWindow::on_homeTimeoutMinusButton_clicked()
{
    if(get_home_timeouts()>0 || allow_negative==true){
        add_home_timeouts(-1);
    }
    ui->homeTimeoutsDisplay->display(get_home_timeouts());
}

void MainWindow::on_awayTimeoutPlusButton_clicked()
{
    add_away_timeouts(+1);

    ui->awayTimeoutsDisplay->display(get_away_timeouts());
}

void MainWindow::on_awayTimeoutMinusButton_clicked()
{
    if(get_away_timeouts()>0 || allow_negative==true){
        add_away_timeouts(-1);
    }

    ui->awayTimeoutsDisplay->display(get_away_timeouts());
}

void MainWindow::on_periodPlusButton_clicked()
{
    add_period(+1);
    set_home_timeouts(1);
    set_away_timeouts(1);
    ui->periodDisplay->display(get_period());
    ui->homeTimeoutsDisplay->display(get_home_timeouts());
    ui->awayTimeoutsDisplay->display(get_away_timeouts());
}

void MainWindow::on_periodMinusButton_clicked()
{
    if(get_period()>0 || allow_negative == true){
        add_period(-1);
    }

    ui->periodDisplay->display(get_period());
}

void MainWindow::on_shotClockStartStopButton_clicked()
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
        ui->shotClockStartStopButton->setEnabled(true);
        if(get_shot_clock()>0 || allow_negative==true){
            add_shot_clock(-1);
            if(get_shot_clock()==0 ){
                shotClockSound.play();
            }
        }
    }

    ui->shotClockDisplay->display(get_shot_clock());
}

void MainWindow::on_shotClockResetButton_clicked()
{
    set_shot_clock(ui->shotClockInput->text().toInt());
    ui->shotClockDisplay->display(get_shot_clock());
}

void MainWindow::on_hornButton_clicked()
{
    shotClockSound.play();
}

void MainWindow::on_gameClockStartStopButton_clicked()
{
    //Main clock
    ui->main_clock_widget->start_stop();
    ui->shotClockStartStopButton->setEnabled(true);

    //Shot clock is synchronized with main clock
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

void MainWindow::on_gameClockResetButton_clicked()
{
    ui->main_clock_widget->set_minutes(ui->gameClockMinutesInput->text().toInt());
    ui->main_clock_widget->set_seconds(ui->gameClockSecondsInput->text().toInt());
    ui->main_clock_widget->showTime();
}

void MainWindow::on_addScoreScreenButton_clicked()
{
    scoreWindowShown = true;
    QRect screenres = QApplication::desktop()->screenGeometry(1/*screenNumber*/);
    scoreWindow = new ScoreDisplay();
    scoreWindow->setAttribute(Qt::WA_ShowWithoutActivating);
    scoreWindow->setWindowFlags(Qt::Tool | Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);
    scoreWindow->move(QPoint(screenres.x(), screenres.y()));
    scoreWindow->resize(screenres.width(), screenres.height());
    scoreWindow->setWindowFlags(Qt::Tool);
    scoreWindow->showFullScreen();
    connect(this, SIGNAL(homePictureChanged(QString)), scoreWindow, SLOT(changeHomePicture(QString)));
    connect(this, SIGNAL(awayPictureChanged(QString)), scoreWindow, SLOT(changeAwayPicture(QString)));
    emit homePictureChanged(homeFilename);
    emit awayPictureChanged(awayFilename);
}

void MainWindow::on_addShotClockScreenButton_clicked()
{
    shotClockWindowShown = true;
    QRect screenres = QApplication::desktop()->screenGeometry(2/*screenNumber*/);
    shotClockWindow = new ShotClockDisplay();
    shotClockWindow->setAttribute(Qt::WA_ShowWithoutActivating);
    shotClockWindow->setWindowFlags(Qt::Tool | Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);
    shotClockWindow->move(QPoint(screenres.x(), screenres.y()));
    shotClockWindow->resize(screenres.width(), screenres.height());

    shotClockWindow->showFullScreen();
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_S)
    {
        //Start Stop button
        on_gameClockStartStopButton_clicked();
    }

    if(event->key() == Qt::Key_R)
    {
        //Reset button
        on_gameClockResetButton_clicked();
    }

    if(event->key() == Qt::Key_PageUp)
    {
        //Start/stop shot clock
        on_shotClockStartStopButton_clicked();
    }

    if(event->key() == Qt::Key_PageDown)
    {
        //Reset shot clock
        on_shotClockResetButton_clicked();
    }

    if(event->key() == Qt::Key_Minus)
    {
        //Reset shot clock to the short value
        on_shotClockShortResetButton_clicked();
    }

    if(event->key() == Qt::Key_Alt)
    {
        //Show/hide shot clock
        toggleShotClockVisibility();
    }
}

void MainWindow::updateScreens(){
    if(scoreWindowShown==true){
        scoreWindow->updateDisplay(get_home_goals(),get_away_goals(),get_shot_clock(), get_period(), this->ui->main_clock_widget->getTime());
    }
    if(shotClockWindowShown==true){
        shotClockWindow->updateDisplay(get_shot_clock(), shotClockHidden);
    }
}

void MainWindow::toggleShotClockVisibility(){
    if(this->ui->shotClockDisplay->isVisible()){
        this->ui->shotClockDisplay->hide();
        shotClockHidden = true;
    }
    else {
        this->ui->shotClockDisplay->show();
        shotClockHidden = false;
    }
}

void MainWindow::changeHomePicture()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Select Image"), "img/", tr("Image Files (*.png *.jpg *.bmp)"));

    if (!fileName.isEmpty()){
        homeFilename = fileName;
        ui->homeLogoLabel->setPixmap(homeFilename);
        emit homePictureChanged(homeFilename);
    }
}

void MainWindow::changeAwayPicture()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Select Image"), "img", tr("Image Files (*.png *.jpg *.bmp)"));

    if (!fileName.isEmpty()){
        awayFilename = fileName;
        ui->awayLogoLabel->setPixmap(awayFilename);
        emit awayPictureChanged(awayFilename);
    }
}

void MainWindow::on_shotClockShortResetButton_clicked()
{
    set_shot_clock(ui->shotClockShortInput->text().toInt());
    ui->shotClockDisplay->display(get_shot_clock());
}
