#ifndef SCOREDISPLAY_H
#define SCOREDISPLAY_H

#include <QWidget>
#include <QTime>

namespace Ui {
class ScoreDisplay;
}

class ScoreDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit ScoreDisplay(QWidget *parent = nullptr);
    ~ScoreDisplay();

public slots:
    void updateDisplay(int home, int away, int shot_clock, int period, QTime time);
    void random();


private:
    Ui::ScoreDisplay *ui;
};


#endif // SCOREDISPLAY_H
