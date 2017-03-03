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
    // Load SQL specific to child class.
    store_add_row_sql();
    store_create_sql();

    // must build table sepparately so new
    // sql can be properly registered
    build_table();
}

DBTableGames::~DBTableGames() {

}

void DBTableGames::store_add_row_sql() {

    sql_template =  "SELECT name FROM sqlite_master WHERE type = \"table\";";

}


void DBTableGames::store_create_sql() {

    std::cout << "Created SQL CREATE command" << std::endl;

    sql_create =  "CREATE TABLE ";
    sql_create += table_name;
    sql_create += " (";
    sql_create += "id INT PRIMARY KEY NOT NULL, ";
    sql_create += "score INTEGER, ";
    sql_create += "name TEXT, ";
    sql_create += "player INTEGER";
    sql_create += ");";

    std::cout << sql_create << std::endl;
}


bool DBTableGames::add_row(int id, int score, std::string name, int player) {
    int   retCode = 0;
    char *zErrMsg = 0;

    char  tempval[128];

    sql_add_row  = "INSERT INTO ";
    sql_add_row += table_name;
    sql_add_row += " ( id, score, name, player ) ";
    sql_add_row += "VALUES (";

    sprintf (tempval, "%d", id);
    sql_add_row += tempval;
    sql_add_row += ", ";

    sprintf (tempval, "%d", score);
    sql_add_row += tempval;
    sql_add_row += ", ";

    sql_add_row += "\"";
    sql_add_row += name;
    sql_add_row += "\", ";

    sprintf (tempval, "%d", player);
    sql_add_row += tempval;
    sql_add_row += ")";

    //std::cout << sql_add_row << std::endl;

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_add_row.c_str(),
                           DBTableGames::cb_add_row,
                           this,
                           &zErrMsg          );

    if(retCode != SQLITE_OK){
        std::cerr << table_name << ": " << sql_add_row << std::endl << "SQL error: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    }

    return retCode;
}


bool DBTableGames::select_all() {

    int   retCode = 0;
    char *zErrMsg = 0;

    std::string sql_select_all  = "SELECT * FROM " + table_name + ";";

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_select_all.c_str(),
                           DBTableGames::cb_select_all,
                           this,
                           &zErrMsg          );

    if(retCode != SQLITE_OK){
        std::cerr << table_name << ": " << sql_select_all << std::endl << "SQL error: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
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

int DBTableGames::cb_select_all(void  *data,
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

    DBTableGames *obj = (DBTableGames *) data;

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
