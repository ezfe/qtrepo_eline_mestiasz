#ifndef LOG_H
#define LOG_H

#include <fstream>
#include <string>

class Log {
public:
    Log(); //Default constructor
    ~Log(); //destructor

    //overload handler operator
    Log& operator<<(const std::string str);

private:

    //The file handler
    std::ofstream fh;
};

#endif // LOG_H
