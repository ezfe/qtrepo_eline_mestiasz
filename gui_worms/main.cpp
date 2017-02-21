#include "wormswindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WormsWindow w;
    w.show();

    return a.exec();
}
