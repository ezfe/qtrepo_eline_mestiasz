#include <iostream>
#include "log.h"

using namespace std;

//Object of type Log instantiated globally
Log err_log("/Users/ezekielelin/Desktop/test.txt");

int main(int argc, char *argv[])
{

    //Here the first err_log << string will be evaled,
    //returning err_log, so the next err_log << can be evalulated.
    err_log << "test2" << "test2" << "test2" << "test2";

    cout << "Hi" << endl;

    err_log.flush();

    err_log.close();

    cout << err_log.isOpen() << endl;

    err_log.open();

    cout << err_log.isOpen() << endl;

    err_log << "yay";

    err_log.flush();

    return 0;
}
