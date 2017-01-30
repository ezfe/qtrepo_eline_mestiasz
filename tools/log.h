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

    /* Open the file handler */
    void open();

    /* Close the file handler */
    void close();

    /* Flush the file handler */
    void flush();

    /* Query the file handler's state */
    bool isOpen();
private:

    std::string filepath;
    //The file handler
    std::ofstream fh;
};

#endif // LOG_H
