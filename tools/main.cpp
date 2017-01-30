#include <iostream>
#include "log.h"

using namespace std;

//Object of type Log instantiated globally
Log err_log;

int main(int argc, char *argv[])
{

    //Here the first err_log << string will be evaled,
    //returning err_log, so the next err_log << can be evalulated.
    err_log << "test" << "test" << "test" << "test";

    cout << "Hi" << endl;

    return 0;
}
