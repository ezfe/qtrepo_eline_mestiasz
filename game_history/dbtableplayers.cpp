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
    build_table();
}

DBTablePlayers::~DBTablePlayers() {

}

std::string DBTablePlayers::create_sql() {

    std::string temp = "";
    temp += "CREATE TABLE ";
    temp += name;
    temp += " (";
    temp += "id INT PRIMARY KEY NOT NULL, ";
    temp += "firstName TEXT, ";
    temp += "lastName TEXT, ";
    temp += "address TEXT";
    temp += ");";

    if (this->database->verbose) {
        std::cout << this->name << "::create_sql()" << std::endl;
        std::cout << temp << std::endl;
    }

    return temp;
}


bool DBTablePlayers::add_row(int id, std::string firstName, std::string lastName, std::string address) {
    int   retCode = 0;
    char *zErrMsg = 0;

    char  tempval[128];

    std::string sql_add_row = "INSERT INTO ";
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
    } else {
        std::cout << "Saved record to " << this->name << std::endl;
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
