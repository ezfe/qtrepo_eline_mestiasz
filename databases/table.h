#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <string>
#include <sqlite3.h>

#include <sys/stat.h>
#include <sys/types.h>

#include "database.h"

class Table {
public:
    Table(Database* database, std::string name);

    void build_table();

    virtual void store_template_sql();
    virtual void store_exist_sql();
    virtual void store_create_sql();
    virtual void store_drop_sql();
    virtual void store_size_sql();

    int dbtemplate();

    bool exists();
    bool create();
    bool drop();
    int size();

    std::string get_name();

    void set_exists(bool state) { table_exists = state; }
    void set_size(int count) { _row_count = count; }

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

// Functions for providing callback functionality to the
// sqlite database repository.  See exists method and callback
// for details about parameters.
int cb_template(void *data, int argc, char **argv, char **azColName);
int cb_exist   (void *data, int argc, char **argv, char **azColName);
int cb_create  (void *data, int argc, char **argv, char **azColName);
int cb_drop    (void *data, int argc, char **argv, char **azColName);
int cb_load    (void *data, int argc, char **argv, char **azColName);
int cb_store   (void *data, int argc, char **argv, char **azColName);
int cb_size    (void *data, int argc, char **argv, char **azColName);

#endif // TABLE_H
