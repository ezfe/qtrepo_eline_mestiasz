#ifndef CONFIG_H
#define CONFIG_H

#include <fstream>
#include <string>
#include <map>

class Config {
public:
    Config();
    ~Config(); // Destructor

    void generateMap();
    void saveState();
    void reloadState();
    void setValue(std::string key, std::string value);
    void printState();
    void setPath(std::string path);
    void setFileName(std::string file_name);
    void clearState();

    std::string getValue(std::string key);

private:
    std::map<std::string, std::string> state;
    std::string path;
    std::string file_name;
};

#endif // CONFIG_H
