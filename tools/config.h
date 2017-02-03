#ifndef CONFIG_H
#define CONFIG_H

#include <fstream>
#include <string>
#include <map>

class Config {
public:
    Config();
    ~Config(); // Destructor

    std::string generateMap();

    void save(std::string path);

private:
    std::map<std::string, std::string> state;
};

#endif // CONFIG_H
