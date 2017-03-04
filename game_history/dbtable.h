/*********************************************************************

Copyright (C) 2015 Jeffrey O. Pfaffmann

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

*********************************************************************/

#ifndef DBTABLE_H
#define DBTABLE_H

#include <iostream>
#include <string>
#include <sqlite3.h>

#include <sys/stat.h>
#include <sys/types.h>

#include "dbtool.h"

/**
 * @brief The DBTable class
 *
 * This class provides the parent functionality for a class that
 * will be implementing the basic table functionality.  The
 * virutal methods also provide examples of the type of
 * functionality that needs to be implemented in the inherited
 * class.
 *
 * There are also several functions that are not part of the
 * class, but are required by the sqlite software function.  The
 * are generally named cb or "call back", indicating that they
 * will be called by the sqlite software to provide functionality
 * back to your code.
 *
 * A called to sqlite_exec is detailed in the exist method, which
 * is how these classes interfaces to the SQLite tool.
 */

class DBTable {

protected:

    // name of the table where data will be stored
    std::string name;

    // reference to the global database tool
    DBTool* database;

    // sql for retrieving table names from the database
    std::string sql_template;

    // default sql for determining if table exists
    virtual std::string exists_sql();

    // default sql for creating associated table
    virtual std::string create_sql() = 0;

    // default sql for dropping the associated table
    virtual std::string drop_sql();

    // default sql for determining number of rows in the table
    virtual std::string size_sql();

    // internal value for storing the result of the last size request
    int  row_cnt;

public:

    // constructors
    DBTable();
    DBTable(DBTool *database, std::string name);

    // destructor
    virtual ~DBTable();

    // method for rebuilding the table regardless of existance
    void build_table();

    // These methods are for storing the base sql commands, these methods
    // can be overloaded for storing your own sql command and should
    // be used as examples for enhancing the functionality of a
    // child class inheriting from this parent class.

    int dbtemplate();

    // methods for performing the activities
    bool exists();
    bool create(); // used
    bool drop();
    int  size();

    std::string get_name();

    void set_size(int cnt) { row_cnt = cnt; }

};

// Functions for providing callback functionality to the
// sqlite database repository.  See exists method and callback
// for details about parameters.
int cb_template(void *data, int argc, char **argv, char **azColName);
int cb_exist   (void *data, int argc, char **argv, char **azColName);
int cb_load    (void *data, int argc, char **argv, char **azColName);
int cb_store   (void *data, int argc, char **argv, char **azColName);
int cb_size    (void *data, int argc, char **argv, char **azColName);

#endif // DBTABLE_H
