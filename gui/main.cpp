#include "enginewindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EngineWindow w;
    w.show();

    return a.exec();
}
