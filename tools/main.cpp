#include <iostream>
#include <vector>
#include "log.h"
#include "config.h"

using namespace std;

//Object of type Log instantiated globally
Log err_log("./test.txt", true);
Config config;

int main(int argc, char *argv[])
{

    //Here the first err_log << string will be evaled,
    //returning err_log, so the next err_log << can be evalulated.
    std::vector<int> v(10, 1);
    err_log << "test " << " test " << " test " << " test " << 1 << " " << 0.11 << 'm' << v;

    err_log.flush();
    err_log.close();
    cout << err_log.isOpen() << endl;
    err_log.open();
    cout << err_log.isOpen() << endl;
    err_log << "yay";
    err_log.flush();


    config.generateMap();
    config.reloadState();
    config.setValue("facebook", "facebook");
    config.saveState();
    config.printState();
    config.clearState();
    config.setFileName("random_01.txt");
    config.reloadState();
    config.saveState();
    config.printState();


    return 0;
}
