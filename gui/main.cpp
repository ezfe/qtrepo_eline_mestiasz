#include "mainwindow.h"
#include <QApplication>

#include "wormswindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    WormsWindow w2;
    w2.show();


    return a.exec();
}
