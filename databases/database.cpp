#include "database.h"

Database::Database() {
    std::cerr << "No name provided to database" << std::endl;
    exit(-1);
}

Database::Database(std::string location) {
    this->path = location;
}

int Database::open() {
    int sqlCode = sqlite3_open(this->path.c_str(), &this->current);
    if (sqlCode) {
        std::cerr << "Database failed to open: " << sqlite3_errmsg(this->current) << std::endl;
        exit(0);
    }
    return sqlCode;
}
