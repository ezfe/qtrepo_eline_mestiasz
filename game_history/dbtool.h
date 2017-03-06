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

#ifndef DBTOOL_H
#define DBTOOL_H

#include <iostream>
#include <string>
#include <sqlite3.h>

#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <set>
#include <map>

/**
 * @brief The Database management tool
 *
 * This object represents the running sqlite3 database
 * instance, which is run as part of a library.  This
 * is the class that loads the sqlite file and will
 * allow for the basic tools for manipulating that object.
 * The Database object is essentally a specialized engine
 * that implements the primary features of a SQL relational
 * database as a local instance.
 */

class DBTool {
private:

    /// Database location
    std::string path;

    sqlite3 *current;

public:

    bool verbose = true;

    // Constructor that if called will cause the program to exit
    // indicating that more information should be provided.
    DBTool();

    // Constructors for loading a database file
    DBTool(std::string path);
    DBTool(const char* path);

    // Destructor that will cause the database to be closed storing
    // the updated contents of the sqlite file.
    ~DBTool();

    std::string get_filepath();

    // Used to manually open the file, and called by each of the
    // constructors.
    int open();

    // Used to manually close the file
    int close();

    // prints state of database
    void print(std::ostream &sout);

    // provides a state check to determine if database is available
    bool isOpen() { return current ? true : false; }

    // Returns a pointer to the current database, only
    // used when absolutely necessary!
    sqlite3* db() { return current; }
};

#endif // DBTOOL_H

