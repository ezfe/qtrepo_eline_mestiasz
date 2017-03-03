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

#include "dbtool.h"

DBTool::DBTool() {
    std::cerr << "Name must be provided to DBTool Class "
              << "during creation.\n";
    exit(-1);
}

DBTool::DBTool(std::string name) {
    //std::cerr << "constructing object 1\n";

    this->name = name;
    this->location = ".";

    open_db();
}


DBTool::DBTool(const char* name) {
    //std::cerr << "constructing object 2\n";

    this->name = name;
    this->location = ".";

    open_db();
}

DBTool::DBTool(const char* location, const char* name) {
    //std::cerr << "constructing object 3\n";

    this->name = name;
    this->location = location;

    open_db();
}


DBTool::DBTool(std::string location, std::string name) {
    //std::cerr << "constructing object 4\n";

    this->name = name;
    this->location = location;

    open_db();
}


DBTool::~DBTool() {

    //std::cerr << "closing object\n";

    sqlite3_close(this->current);
    this->current = NULL;
}


/** Method that will open the provided database.
 */
int DBTool::open_db() {

    int retCode = 0;

    std::string full_name = this->location + "/" + this->name;

    // open the database --------------------

    retCode = sqlite3_open(full_name.c_str(), &this->current);

    if( retCode ){
        std::cerr << "Database does not open: " << sqlite3_errmsg(current) << std::endl;
        std::cerr << "File: " << full_name << std::endl;
        exit(0);
    }else{
        std::cerr << "Opened database successfully\n";
    }

    return retCode;
}


void DBTool::print(std::ostream &sout) {

    sout << "DB Name : " << name     << std::endl;
    sout << "DB Loc  : " << location << std::endl;

    sout << "Status  : "
         << ( db_open() ? "open" : "closed" )
         << std::endl;
}
