#ifndef LOG_H
#define LOG_H

#include <fstream>
#include <string>
#include <vector>

class Log {
public:
    Log(std::string p, bool empty); //Default constructor
    ~Log(); //destructor

    //overload handler operator
    Log& operator << (const std::string str);
    Log& operator << (const int num);
    Log& operator << (const double d);
    Log& operator << (const char c);
    Log& operator << (const std::vector<int> v);

    /* Open the file handler */
    void open();

    /* Open as an empty file */
    void openAsEmpty();

    /* Close the file handler */
    void close();

    /* Flush the file handler */
    void flush();

    /* Query the file handler's state */
    bool isOpen();
private:
    /* Path of file */
    std::string filepath;

    /* File handler */
    std::ofstream fh;

    /* Whether the file handler is opened */
    bool isOpenState;
};

#endif // LOG_H
