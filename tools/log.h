#ifndef LOG_H
#define LOG_H

#include <fstream>
#include <string>

class Log {
public:
    Log(std::string p); //Default constructor
    ~Log(); //destructor

    //overload handler operator
    Log& operator<<(const std::string str);

    void open();
    void close();
    void flush();

private:

    std::string filepath;
    //The file handler
    std::ofstream fh;
};

#endif // LOG_H
