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

    void generateMap();
    void printState();

    /***************
     * File System *
     ***************/

    void saveState();
    void reloadState();
    void setPath(std::string path);
    void setFileName(std::string file_name);
    void setCompletePath(std::string complete_path);

    /****************
     * Manipulation *
     ****************/

    std::string getValue(std::string key);
    void setValue(std::string key, std::string value);
    void clearState();

    std::string get_filename();
    std::string get_filepath();
private:
    std::map<std::string, std::string> state;
    std::string path;
    std::string file_name;
};

#endif // CONFIG_H
