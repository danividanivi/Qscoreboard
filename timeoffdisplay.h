#ifndef TIMEOFFDISPLAY_H
#define TIMEOFFDISPLAY_H

#include <QWidget>

namespace Ui {
class TimeOffDisplay;
}

class TimeOffDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit TimeOffDisplay(QWidget *parent = nullptr);
    ~TimeOffDisplay();

private:
    Ui::TimeOffDisplay *ui;
};

#endif // TIMEOFFDISPLAY_H
