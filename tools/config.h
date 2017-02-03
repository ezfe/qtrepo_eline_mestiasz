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
};

#endif // CONFIG_H
