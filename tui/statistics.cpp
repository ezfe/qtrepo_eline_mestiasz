#include "statistics.h"

Statistics::Statistics(PlayerGameHistory* pgh) : MenuItemScreen(pgh) {

}

Statistics::~Statistics(){

}

void Statistics::controller(){
    clear();
    int cmd = getch();
}
