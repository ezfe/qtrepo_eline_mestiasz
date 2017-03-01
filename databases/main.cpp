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

#include <iostream>

#include "dbtool.h"
#include "dbtableplayers.h"

int main() {

    // generate database object
    DBTool *dbtool = new DBTool("TestTableDB");

    // print its state
    dbtool->print(std::cout);

    // generate a new table
    DBTablePlayers *ext = new DBTablePlayers(dbtool, "PlayerList");

    // add information to the new table
    ext->add_row(0, "Ezekiel", "Elin", "South College");
    ext->add_row(1, "Sydney", "Schock", "Marquis");

    ext->select_all();

    delete ext;

    return 0;
}

