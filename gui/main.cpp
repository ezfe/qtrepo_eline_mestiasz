#include "mainwindow.h"
#include <QApplication>

#include "wormswindow.h"
#include "../gui_robots/robotswindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    WormsWindow w2;
    w2.show();

    RobotsWindow w3;
    w3.show();


    return a.exec();
}
