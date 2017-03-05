#include "statistics.h"

Statistics::Statistics(PlayerGameHistory* pgh) : MenuItemScreen(pgh) {

}

Statistics::~Statistics(){

}

void Statistics::controller(){
    clear();
    mvprintw(4, 10, "Welcome to virtual world! Enjoy your time :)");
    int cmd = getch();
}
