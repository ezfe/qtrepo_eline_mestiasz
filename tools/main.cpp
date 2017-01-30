#include <iostream>
#include "log.h"
#include "config.h"

using namespace std;

//Object of type Log instantiated globally
Log err_log("./test.txt");
Config config;

int main(int argc, char *argv[])
{

    //Here the first err_log << string will be evaled,
    //returning err_log, so the next err_log << can be evalulated.
    err_log << "test" << "test" << "test" << "test";

    err_log.flush();

    err_log.close();

    cout << err_log.isOpen() << endl;

    err_log.open();

    cout << err_log.isOpen() << endl;

    err_log << "yay";

    err_log.flush();

    config.generateMap();

    return 0;
}
