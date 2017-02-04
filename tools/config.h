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
    void saveState(std::string path);
    void reloadState(std::string path);
    void setValue(std::string key, std::string value);
    void printState();

    std::string getValue(std::string key);

private:
    std::map<std::string, std::string> state;
};

#endif // CONFIG_H
