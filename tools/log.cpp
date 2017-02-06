#include "log.h"

Log::Log() {
    SHOW_WHERE;
    filepath = "./log.txt";
    isOpenState = isOpen();
    open();
}

/* Set file path and open() file handler */
Log::Log(std::string p, bool empty) {
    SHOW_WHERE;
    filepath = p;
    isOpenState = isOpen();
    empty ? openAsEmpty() : open();
}

Log::Log(Log &obj) {
    SHOW_WHERE;
    filepath = obj.filepath;
    isOpenState = isOpen();
}

void Log::operator =(Log &obj) {
    filepath = obj.filepath;
    isOpenState = isOpen();
}

/* close() file handler */
Log::~Log() {
    SHOW_WHERE;
    fh.close();
}

/*!
 * \brief Close file handler
 */
void Log::close() {
    SHOW_WHERE;
    try {
        fh.close();
    } catch (std::exception &e) {
        std::cout << "An error occurred closing the file" << std::endl;
    }
    isOpenState = isOpen();
}

/*!
 * \brief Open file handler using filepath
 */
void Log::open() {
    SHOW_WHERE;
    try {
        fh.open(filepath, std::ofstream::out | std::ofstream::app);
    } catch (std::exception &e) {
        std::cout << "An error occurred opening the file" << std::endl;
    }

    isOpenState = isOpen();
    fh << std::endl;
}

/*!
 * \brief Open the file as an empty one
 */
void Log::openAsEmpty() {
    SHOW_WHERE;
    try {
        fh.open(filepath, std::ofstream::out | std::ofstream::trunc);
    } catch (std::exception &e) {
        std::cout << "An error occurred opening the file" << std::endl;
    }

    isOpenState = isOpen();
}

/*!
 * \brief Flush file handler
 */
void Log::flush() {
    SHOW_WHERE;
    try {
        fh.flush();
    } catch (std::exception &e) {
        std::cout << "An error occurred flushing the file" << std::endl;
    }
}

/*!
 * \brief Query the file handler's state
 */
bool Log::isOpen() {
    return fh.is_open();
}

// The overload operator will process the incoming strings, integers, doubles, chars and
// integer vectors, then return itself as a reference.
// This allows chaining of multiple filehandler operations.

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

