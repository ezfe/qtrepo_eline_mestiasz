#include "log.h"
#include <iostream>

//In the default constructor the file handler is opened
Log::Log(std::string p) {
    filepath = p;
    std::cout << "Constructor called" << std::endl;
    open();
}

//In the destructor the file handler is closed
Log::~Log() {
    std::cout << "Destructor called" << std::endl;
    fh.close();
}

void Log::close() {
    fh.close();
}

void Log::open() {
    fh.open(filepath, std::ofstream::out | std::ofstream::app);
}

void Log::flush() {
    fh.flush();
}

bool Log::isOpen() {
    return fh.is_open();
}

//The overload operator will process the incoming string, then return
//itself as a reference. This allows chaining of multiple filehandler
//operations.
Log& Log::operator <<(std::string str) {
    fh << str;
    return *this;
}
