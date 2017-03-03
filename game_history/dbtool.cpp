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
              << "during creation." << std::endl;
    exit(-1);
}

DBTool::DBTool(std::string name) {
    this->name = name;
    this->location = ".";

    open();
}

DBTool::DBTool(const char* name) {
    this->name = name;
    this->location = ".";

    open();
}

DBTool::DBTool(const char* location, const char* name) {
    this->name = name;
    this->location = location;

    open();
}


DBTool::DBTool(std::string location, std::string name) {
    this->name = name;
    this->location = location;

    open();
}


DBTool::~DBTool() {
    sqlite3_close(this->current);
    this->current = nullptr;
}

/**
 * @brief Get the complete file path
 * @return complete filepath
 */
std::string DBTool::get_filepath() {
    return this->location + "/" + this->name;
}

/**
 * @brief Method that will open the provided database.
 * @return sqlite3 response code
 */
int DBTool::open() {
    // open the database --------------------

    int retCode = sqlite3_open(get_filepath().c_str(), &this->current);

    if (retCode != SQLITE_OK) {
        std::cerr << "Database error: " << sqlite3_errmsg(current) << std::endl;
        std::cerr << "File: " << get_filepath() << std::endl;
        exit(0);
    } else {
        std::cerr << "Opened database successfully\n";
    }

    return retCode;
}


void DBTool::print(std::ostream &sout) {
    sout << " DB Name: " << name     << std::endl;
    sout << "Location: " << location << std::endl;

    sout << "Status: "
         << ( isOpen() ? "open" : "closed" )
         << std::endl;
}
