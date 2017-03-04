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

DBTool::DBTool(std::string path) {
    this->path = path;
    open();
}

DBTool::DBTool(const char* path) {
    this->path = path;
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
    return this->path;
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

/**
 * @brief Method that will close the provided database.
 * @return sqlite3 response code
 */
int DBTool::close() {
    // close the database --------------------

    int retCode = sqlite3_close(this->current);

    if (retCode != SQLITE_OK) {
        std::cerr << "Database error: " << sqlite3_errmsg(current) << std::endl;
        std::cerr << "File: " << get_filepath() << std::endl;
        exit(0);
    } else {
        std::cerr << "Closed database successfully\n";
    }

    return retCode;
}


void DBTool::print(std::ostream &sout) {
    sout << " DB: " << path << std::endl;

    sout << "Status: "
         << ( isOpen() ? "open" : "closed" )
         << std::endl;
}
