#ifndef SHOTCLOCKDISPLAY_H
#define SHOTCLOCKDISPLAY_H

#include <QWidget>

namespace Ui {
class ShotClockDisplay;
}

class ShotClockDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit ShotClockDisplay(QWidget *parent = nullptr);
    ~ShotClockDisplay();

public slots:
    void updateDisplay(int seconds, bool hide);

private:
    Ui::ShotClockDisplay *ui;
};

#endif // SHOTCLOCKDISPLAY_H
