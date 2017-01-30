#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <map>

class Config {
public:
    Config();
    ~Config(); // Destructor

    std::string generateMap();
};

#endif // CONFIG_H
