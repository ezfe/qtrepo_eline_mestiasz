#include <iostream>
#include <vector>
#include "log.h"
#include "config.h"

using namespace std;

//Object of type Log instantiated globally
Log err_log("./test.txt", true);
Config config;
Config config_01(config);

int main(int argc, char *argv[])
{

    //Here the first err_log << string will be evaled,
    //returning err_log, so the next err_log << can be evalulated.
    std::vector<int> v(10, 1);
    err_log << "test " << " test " << " test " << " test " << 1 << " " << 0.11 << 'm' << v;

    err_log.flush();
    err_log.close();
    cout << err_log.is_open() << endl;
    err_log.open();
    cout << err_log.is_open() << endl;
    err_log << "yay";
    err_log.flush();
    err_log.close();


    config.generate_map();
    config.set_value("facebook", "facebook");
    config.save_state();
    config.print_state();
    config.set_file_name("random_01.txt");
    config.save_state();
    config.print_state();


    return 0;
}
