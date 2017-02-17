#ifndef LOG_H
#define LOG_H

#include <fstream>
#include <string>
#include <vector>
#include <iostream>

#include "baseclass.h"

class Log : public BaseClass {
public:
    Log();
    Log(std::string p, bool empty); //Default constructor
    Log(Log &obj);

    void operator=(Log &obj);

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
    void open_as_empty();

    /* Close the file handler */
    void close();

    /* Flush the file handler */
    void flush();

    /* Query the file handler's state */
    bool is_open();

    std::string get_filepath();
private:
    /* Path of file */
    std::string filepath;

    /* File handler */
    std::ofstream fh;

    /* Whether the file handler is opened */
    bool isOpenState;
};

#endif // LOG_H
