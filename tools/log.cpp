#include "log.h"
#include <iostream>
#include <vector>

/* Set file path and open() file handler */
Log::Log(std::string p, bool empty) {
    filepath = p;
    isOpenState = isOpen();
    empty ? openAsEmpty() : open();
}

/* close() file handler */
Log::~Log() {
    fh.close();
}

/* Close file handler */
void Log::close() {
    fh.close();
    isOpenState = isOpen();
}

/* Open file handler using filepath */
void Log::open() {
    if (isOpen()) {
        close();
    }
    fh.open(filepath, std::ofstream::out | std::ofstream::app);
    isOpenState = isOpen();
    fh << std::endl;
}

/* Open the file as an empty one */
void Log::openAsEmpty() {
    if (isOpen()) {
        close();
    }
    fh.open(filepath, std::ofstream::out | std::ofstream::trunc);
    isOpenState = isOpen();
}

/* Flush file handler */
void Log::flush() {
    fh.flush();
}

/* Query the file handler's state */
bool Log::isOpen() {
    return fh.is_open();
}

//The overload operator will process the incoming string, then return
//itself as a reference. This allows chaining of multiple filehandler
//operations.
Log& Log::operator << (std::string str) {
    fh << str;
    return *this;
}

Log& Log::operator << (int num) {
    fh << num;
    return *this;
}

Log& Log::operator << (double d){
    fh << d;
    return *this;
}

Log& Log::operator << (char c){
    fh << c;
    return *this;
}

Log& Log::operator << (std::vector<int> v){
    for(int i : v){
        fh << i;
    }
    return *this;
}

//Log& Log::operator << (bool b){
//    fh << b;
//    return *this;
//}
