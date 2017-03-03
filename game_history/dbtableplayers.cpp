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

#include "dbtableplayers.h"

// Default constructor.
DBTablePlayers::DBTablePlayers() {

}

// Constructor for identying the dbtool and table name.
DBTablePlayers::DBTablePlayers(DBTool *db, std::string name): DBTable (db, name) {
    // Load SQL specific to child class.
    store_add_row_sql();
    store_create_sql();

    // must build table sepparately so new
    // sql can be properly registered
    build_table();
}

DBTablePlayers::~DBTablePlayers() {

}

void DBTablePlayers::store_add_row_sql() {

    sql_template =  "SELECT name FROM sqlite_master WHERE type = \"table\";";

}


void DBTablePlayers::store_create_sql() {

    std::cout << "Created SQL CREATE command" << std::endl;

    sql_create =  "CREATE TABLE ";
    sql_create += name;
    sql_create += " (";
    sql_create += "id INT PRIMARY KEY NOT NULL, ";
    sql_create += "firstName TEXT, ";
    sql_create += "lastName TEXT, ";
    sql_create += "address TEXT";
    sql_create += ");";

    std::cout << sql_create << std::endl;
}


bool DBTablePlayers::add_row(int id, std::string firstName, std::string lastName, std::string address) {
    int   retCode = 0;
    char *zErrMsg = 0;

    char  tempval[128];

    sql_add_row  = "INSERT INTO ";
    sql_add_row += this->name;
    sql_add_row += " ( id, firstName, lastName, address ) ";
    sql_add_row += "VALUES (";

    sprintf (tempval, "%d", id);
    sql_add_row += tempval;
    sql_add_row += ", ";

    sql_add_row += "\"";
    sql_add_row += std::string(firstName);
    sql_add_row += "\", ";

    sql_add_row += "\"";
    sql_add_row += std::string(lastName);
    sql_add_row += "\", ";

    sql_add_row += "\"";
    sql_add_row += std::string(address);
    sql_add_row += "\" )";

    //std::cout << sql_add_row << std::endl;

    retCode = sqlite3_exec(this->database->db(),
                           sql_add_row.c_str(),
                           DBTablePlayers::cb_add_row,
                           this,
                           &zErrMsg          );

    if(retCode != SQLITE_OK){
        std::cerr << name << ": " << sql_add_row << std::endl << "SQL error: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    }

    return retCode;
}


bool DBTablePlayers::select_all() {

    int   retCode = 0;
    char *zErrMsg = 0;

    std::string sql_select_all  = "SELECT * FROM " + name + ";";

    retCode = sqlite3_exec(this->database->db(),
                           sql_select_all.c_str(),
                           DBTablePlayers::cb_select_all,
                           this,
                           &zErrMsg          );

    if(retCode != SQLITE_OK){
        std::cerr << name << ": " << sql_select_all << std::endl << "SQL error: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    }

    return retCode;
}


int DBTablePlayers::cb_add_row(void  *data,
               int    argc,
               char **argv,
               char **azColName)
{



    std::cerr << "cb_add_row being called\n";

    if(argc < 1) {
        std::cerr << "No data presented to callback "
                  << "argc = " << argc
                  << std::endl;
    }

    int i;

    DBTablePlayers *obj = (DBTablePlayers *) data;

    std::cout << "------------------------------\n";
    std::cout << obj->get_name()
              << std::endl;

    for(i = 0; i < argc; i++){
        std::cout << azColName[i]
                  << " = "
                  <<  (argv[i] ? argv[i] : "NULL")
                  << std::endl;
    }

    return 0;
}

int DBTablePlayers::cb_select_all(void  *data,
                  int    argc,
                  char **argv,
                  char **azColName)
{



    std::cerr << "cb_select_all being called\n";

    if(argc < 1) {
        std::cerr << "No data presented to callback "
                  << "argc = " << argc
                  << std::endl;
    }

    int i;

    DBTablePlayers *obj = (DBTablePlayers *) data;

    std::cout << "------------------------------\n";
    std::cout << obj->get_name()
              << std::endl;

    for(i = 0; i < argc; i++){
        std::cout << azColName[i]
                  << " = "
                  <<  (argv[i] ? std::string(argv[i]) : "NULL")
                  << std::endl;
    }

    return 0;
}
