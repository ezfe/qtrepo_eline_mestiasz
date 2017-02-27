#ifndef TABLE_H
#define TABLE_H

#include "database.h"

class Table {
public:
    Table();

protected:
    std::string name;
    Database* current;

    std::string sql_template;
    std::string sql_exists;
    std::string sql_create;
    std::string sql_drop;
    std::string sql_size;
    std::string sql_add_row;

    bool table_exists;
    int _row_count;
};

#endif // TABLE_H
