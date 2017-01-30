#include "log.h"
#include <iostream>

//In the default constructor the file handler is opened
Log::Log() {
    std::cout << "Constructor called" << std::endl;
    fh.open("/Users/ezekielelin/Desktop/test.txt", std::ofstream::out | std::ofstream::app);
}

//In the destructor the file handler is closed
Log::~Log() {
    std::cout << "Destructor called" << std::endl;
    fh.close();
}

//The overload operator will process the incoming string, then return
//itself as a reference. This allows chaining of multiple filehandler
//operations.
Log& Log::operator <<(std::string str) {
    fh << str;
    return *this;
}
