#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <string>
#include <sqlite3.h>

#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <set>
#include <map>

class Database {
public:
    Database();
    Database(std::string location);

    int open();
    bool is_open() { return current ? true : false; }
    sqlite3* db() { return current; }

private:
    std::string path;

    sqlite3* current;
};

#endif // DATABASE_H
