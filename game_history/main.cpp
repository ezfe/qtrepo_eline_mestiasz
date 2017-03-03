#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
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
}
