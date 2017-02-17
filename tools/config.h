#ifndef CONFIG_H
#define CONFIG_H

#include <fstream>
#include <string>
#include <map>
#include <iostream>
#include <vector>

#include "baseclass.h"

class Config : public BaseClass{
public:
    Config();
    Config(std::string pathToFile);
    Config(Config &obj);

    void operator=(Config &obj);

    ~Config();

    void generate_map();
    void print_state();

    /***************
     * File System *
     ***************/

    void save_state();
    void reload_state();
    void set_path(std::string path);
    void set_file_name(std::string file_name);
    void set_complete_path(std::string complete_path);

    /****************
     * Manipulation *
     ****************/

    std::string get_value(std::string key);
    void set_value(std::string key, std::string value);
    void clear_state();

    std::string get_filename();
    std::string get_filepath();
private:
    std::map<std::string, std::string> state;
    std::string path;
    std::string file_name;
};

#endif // CONFIG_H
