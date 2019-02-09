#include "mainwindow.h"
#include "scoredisplay.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowFlags(Qt::Window | Qt::WindowMaximizeButtonHint | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
    QRect screenres = QApplication::desktop()->screenGeometry(0/*screenNumber*/);
    w.move(QPoint(screenres.x(), screenres.y()));
    w.resize(screenres.width(), screenres.height());
    w.showFullScreen();
    w.showFullScreen();   

    return a.exec();
}
