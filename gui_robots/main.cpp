#include "robotswindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RobotsWindow w;
    w.show();

    return a.exec();
}
