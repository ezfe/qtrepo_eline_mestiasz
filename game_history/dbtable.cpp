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

#include "dbtable.h"

// Default constructor that is only called when the software
// developer uses the package incorrectly.
DBTable::DBTable() {
    std::cerr << "Table name must be provided "
              << "for DBTable Class during "
              << "construction.\n"
              << "Exiting\n";
    exit(-1);
}

// Constructor taking a pointer to the DB tool and name
// of the table that will be represented by this class.
DBTable::DBTable(DBTool* db, std::string name) {
    // Store table name and reference to db.
    this->database = db;
    this->name = name;
}

// This should be called by the child constructor but
// is used to build a table in the database if the table
// does not exist.
void DBTable::build_table() {
    if (!this->exists()) {
        this->create();
    }
}

// Deconstructor
DBTable::~DBTable() {

}

// SQL used to determine if a specific table exists
// in the database.
std::string DBTable::exists_sql() {
    std::string temp  = "SELECT count(*) FROM sqlite_master ";
                temp += "WHERE type = \"table\" ";
                temp += "and name = \"" + this->name + "\";";
    return temp;
}

// SQL for removing the table from the database.
std::string DBTable::drop_sql() {
    return "DROP TABLE IF EXISTS " + this->name + ";";
}

// SQL to determine number of records in the database.
std::string DBTable::size_sql() {
    return "SELECT count(*) FROM " + this->name + ";";
}

// Determine if table exists.
bool DBTable::exists() {
    // Initialize local variables.
    int   retCode = SQLITE_ERROR;

    sqlite3_stmt* sqlStatement = nullptr;
    retCode = sqlite3_prepare_v2(this->database->db(), this->exists_sql().c_str(), -1, &sqlStatement, nullptr);
    if (retCode == SQLITE_OK && sqlStatement != nullptr) {
        retCode = sqlite3_step(sqlStatement);
        sqlite3_finalize(sqlStatement);
        if (retCode == SQLITE_ROW) {
            return true;
        } else {
            return false;
        }
    } else {
        std::cerr << exists_sql() << std::endl;
        std::cerr << "SQL error: " << sqlite3_errmsg(this->database->db()) << std::endl;
        sqlite3_finalize(sqlStatement);
        return false;
    }
}

// Create the db table.
bool DBTable::create() {

    // Initialize local variables.
    int   retCode = 0;
    char *zErrMsg = 0;

    // Call sqlite to run the SQL call using the
    // callback to store any results.
    retCode = sqlite3_exec(this->database->db(), this->create_sql().c_str(), 0, 0, &zErrMsg);

    // Process a failed call.
    if(retCode != SQLITE_OK){
        std::cerr << this->create_sql() << std::endl;
        std::cerr << "SQL error: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
        return false;
    } else {
        std::cout << "Created table " << this->name << std::endl;
        return true;
    }
}

// Removes the db table from the database.
bool DBTable::drop() {

    // Initialize local variables.
    int   retCode = 0;
    char *zErrMsg = 0;

    retCode = sqlite3_exec(this->database->db(), drop_sql().c_str(), 0, 0, &zErrMsg);

    // Process a failed call.
    if(retCode != SQLITE_OK){
        std::cerr << drop_sql() << std::endl;
        std::cerr << "SQL error: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
        return false;
    } else {
        return true;
    }
}

// Determines the number of rows in the table.
int DBTable::size() {

    // Initialize local variables.
    int   retCode = 0;
    char *zErrMsg = 0;

    // Call sqlite to run the SQL call using the
    // callback to store any results.
    retCode = sqlite3_exec(this->database->db(),
                           this->size_sql().c_str(),
                           cb_size,
                           this,
                           &zErrMsg          );

    // Process a failed call.
    if( retCode != SQLITE_OK ){

        std::cerr << size_sql()
                  << std::endl;

        std::cerr << "SQL error: "
                  << zErrMsg
                  << std::endl;

        sqlite3_free(zErrMsg);
    }

    // Return the number of rows in table.
    return row_cnt;
}

// The callback after the size is computed.   SQLite
// will pass the results of the call and this function
// will manipulate and make changes to the DBTable object.
int cb_size(void  *data,
            int    argc,
            char **argv,
            char **azColName){

    // If no data is presented generate error message.
    if(argc < 1) {
        std::cerr << "No data presented to callback "
                  << "argc = " << argc
                  << std::endl;
    } else {

        // Store size in object.
        DBTable *obj = (DBTable *) data;
        obj->set_size(atoi(argv[0]));
    }

    return 0;
}

std::string DBTable::get_name() {
    return name;
}

std::string DBTable::select_all_sql() {
    return "SELECT * FROM " + this->name + ";";
}
