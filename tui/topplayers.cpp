#include "topplayers.h"

TopPlayers::TopPlayers(PlayerGameHistory* pgh) : MenuItemScreen(pgh){

}

TopPlayers::~TopPlayers(){

}

void TopPlayers::controller(){
    clear();
    mvprintw(4, 10, "Welcome to virtual world! Enjoy your time :)");
    int cmd = getch();
}
