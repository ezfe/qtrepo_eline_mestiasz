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
    this->name  = name;

    // Register the different sql calls for the
    // parent class.
    store_create_sql();

    sql_add_row = "";
}

// This should be called by the child constructor but
// is used to build a table in the database if the table
// does not exist.
void DBTable::build_table() {

    // determine if table exists
    exist();

    if (!table_exists) {

        // if it does not exist create table
        create();
    }
}

// Deconstructor
DBTable::~DBTable() {

}

// SQL used to get a list of all tables in the DB tool.
void DBTable::store_template_sql() {

    sql_template =  "SELECT name ";
    sql_template += "FROM   sqlite_master ";
    sql_template += "WHERE";
    sql_template += "    type = \"table\"";
    sql_template += ";";

}

// SQL used to determine if a specific table exists
// in the database.
std::string DBTable::exists_sql() {
    std::string temp  = "SELECT count(*) FROM sqlite_master ";
                temp += "WHERE type = \"table\" ";
                temp += "and name = \"" + this->name + "\";";
    return temp;
}

// SQL used to create the table in the database.  The
// code provided here is just an example and should
// be specified in child database.
void DBTable::store_create_sql() {
    // std::cerr << "store_create_sql DBTable\n"
    // 	    << &sql_create << "\n";

//    sql_create =  "CREATE TABLE ";
//    sql_create += table_name;
//    sql_create += " ( ";
//    sql_create += "  id INT PRIMARY KEY NOT NULL, ";
//    sql_create += "  item0 TEXT NOT NULL,";
//    sql_create += "  item1 INT  NOT NULL, ";
//    sql_create += "  item2 CHAR(50),";
//    sql_create += "  item3 REAL";
//    sql_create += " );";

}

// SQL for removing the table from the database.
std::string DBTable::drop_sql() {
    return "DROP TABLE " + this->name + ";";
}

// SQL to determine number of records in the database.
std::string DBTable::size_sql() {
    return "SELECT count(*) FROM " + this->name + ";";
}

// Method for calling the template DB SQL above.
int DBTable::dbtemplate() {

    // Initialize local variables.
    int   retCode = 0;
    char *zErrMsg = 0;

    // Call sqlite to run the SQL call using the
    // callback to store any results.
    retCode = sqlite3_exec(database->db(),
                           sql_template.c_str(),
                           cb_template,
                           this,
                           &zErrMsg);

    if( retCode != SQLITE_OK ){

        std::cerr << sql_template
                  << std::endl;

        std::cerr << "SQL error: "
                  << zErrMsg
                  << std::endl;

        sqlite3_free(zErrMsg);
    }

    return retCode;
}

int cb_template(void  *data,
                int    argc,
                char **argv,
                char **azColName){

    if(argc < 1) {
        std::cerr << "No data presented to callback "
                  << "argc = " << argc
                  << std::endl;
    }

    return 0;
}

// Determine if table exists.
bool DBTable::exist() {

    // Initialize local variables.
    int   retCode = 0;
    char *zErrMsg = 0;

    // Call sqlite to run the SQL call using the
    // callback to store any results.  The parameters
    // are identified as follows:
    // 1. Provide reference to sqlite object in dbtool.
    // 2. Provide the SQL command as a C string.
    // 3. Provide pointer to callback function coded below.
    // 4. Pointer to the DBTable object.
    // 5. Pointer to varible where sqlite will place error code.
    retCode = sqlite3_exec(this->database->db(),
                           exists_sql().c_str(),
                           cb_exist,
                           this,
                           &zErrMsg          );

    // Process return code.
    if( retCode != SQLITE_OK ){

        std::cerr << exists_sql()
                  << std::endl;

        std::cerr << "SQL error: "
                  << zErrMsg
                  << std::endl;

        sqlite3_free(zErrMsg);
    }

    return retCode;
}

// callback to determine if table exists.  SQLite
// will pass the results of the call and this function
// will manipulate and make changes to the DBTable object.
int cb_exist(void  *data,        // pointer to the DBTable object.
             int    argc,        // number of data columns
             char **argv,        // the actual data columns
             char **azColName){  // the data column names


    if(argc != 1) {

        // If call fails, generate error message.
        std::cerr << "More than one item returned "
                  << "argc = " << argc
                  << std::endl;
    } else {

        DBTable *obj = (DBTable *) data;

        if (atoi(argv[0])) {
            //std::cerr << "setting exists\n";
            obj->set_exists(true);
        } else {
            //std::cerr << "unsetting exists\n";
            obj->set_exists(false);
        }
    }


    return 0;
}

// Create the db table.
bool DBTable::create() {

    // Initialize local variables.
    int   retCode = 0;
    char *zErrMsg = 0;

    // Call sqlite to run the SQL call using the
    // callback to store any results.
    retCode = sqlite3_exec(this->database->db(),
                           sql_create.c_str(),
                           cb_create,
                           this,
                           &zErrMsg          );

    std::cout << sql_create << std::endl;

    // Process a failed call.
    if( retCode != SQLITE_OK ){
        std::cerr << sql_create << std::endl;
        std::cerr << "SQL error: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    }

    // Return the code.
    return retCode;
}

// The callback after the table is created.   SQLite
// will pass the results of the call and this function
// will manipulate and make changes to the DBTable object.
int cb_create(void  *data,
              int    argc,
              char **argv,
              char **azColName){

    // Create failed, generate error message.
    if(argc < 1) {
        std::cerr << "No data presented to callback "
                  << "argc = " << argc
                  << std::endl;
    }

    // Commented code prints information returned by
    // sqlite.

    // std::cout << "------------------------------\n";
    // std::cout << obj->get_name()
    // 	    << std::endl;

    // int i;
    // for(i = 0; i < argc; i++){
    //   std::cout << azColName[i]
    // 	      << " = "
    // 	      <<  (argv[i] ? argv[i] : "NULL")
    // 	      << std::endl;
    // }

    // Return the code.
    return 0;
}

// Removes the db table from the database.
bool DBTable::drop() {

    // Initialize local variables.
    int   retCode = 0;
    char *zErrMsg = 0;

    // Call sqlite to run the SQL call using the
    // callback to store any results.
    retCode = sqlite3_exec(this->database->db(),
                           drop_sql().c_str(),
                           cb_drop,
                           this,
                           &zErrMsg          );

    // Process a failed call.
    if( retCode != SQLITE_OK ){

        std::cerr << drop_sql()
                  << std::endl;

        std::cerr << "SQL error: "
                  << zErrMsg
                  << std::endl;

        sqlite3_free(zErrMsg);
    }

    //
    return retCode;
}

// The callback after the table is droped.   SQLite
// will pass the results of the call and this function
// will manipulate and make changes to the DBTable object.
int cb_drop(void  *data,
            int    argc,
            char **argv,
            char **azColName){


    // Table not dropped, generate error message.
    if(argc < 1) {
        std::cerr << "No data presented to callback "
                  << "argc = " << argc
                  << std::endl;
    }

    // std::cout << "------------------------------\n";
    // std::cout << obj->get_name()
    // 	    << std::endl;

    // int i;
    // for(i = 0; i < argc; i++){
    //   std::cout << azColName[i]
    // 	      << " = "
    // 	      <<  (argv[i] ? argv[i] : "NULL")
    // 	      << std::endl;
    // }

    return 0;
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
