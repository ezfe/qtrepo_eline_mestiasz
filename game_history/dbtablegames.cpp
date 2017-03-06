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

#include "dbtablegames.h"

// Default constructor.
DBTableGames::DBTableGames() {

}

// Constructor for identying the dbtool and table name.
DBTableGames::DBTableGames(DBTool *db, std::string name): DBTable (db, name) {
    build_table();
}

DBTableGames::~DBTableGames() {

}

std::string DBTableGames::create_sql() {


    std::string temp = "";
    temp =  "CREATE TABLE ";
    temp += this->name;
    temp += " (";
    temp += "id INT PRIMARY KEY NOT NULL, ";
    temp += "score INTEGER, ";
    temp += "name TEXT, ";
    temp += "player INTEGER";
    temp += ");";

    if (this->database->verbose) {
        std::cout << this->name << "::create_sql()" << std::endl;
        std::cout << temp << std::endl;
    }

    return temp;
}


bool DBTableGames::add_row(int id, int score, std::string name, int player) {
    int   retCode = 0;
    char *zErrMsg = 0;

    char  tempval[128];

    std::string temp = "INSERT INTO " + this->name;
                temp += " ( id, score, name, player ) ";
                temp += "VALUES (";

    sprintf (tempval, "%d", id);
    temp += tempval;
    temp += ", ";

    sprintf (tempval, "%d", score);
    temp += tempval;
    temp += ", ";

    temp += "\"" + name + "\"";
    temp += ", ";

    sprintf (tempval, "%d", player);
    temp += tempval;

    temp += ");";


    retCode = sqlite3_exec(this->database->db(),
                           temp.c_str(),
                           DBTableGames::cb_add_row,
                           this,
                           &zErrMsg          );

    if (retCode != SQLITE_OK) {
        std::cerr << name << ": " << temp << std::endl << "SQL error: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    } else {
        std::cout << "Saved record to " << this->name << std::endl;
    }

    return retCode;
}

int DBTableGames::cb_add_row(void  *data,
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

    DBTableGames *obj = (DBTableGames *) data;

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
