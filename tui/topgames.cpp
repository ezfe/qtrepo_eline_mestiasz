#include "topgames.h"

TopGames::TopGames(PlayerGameHistory* pgh) : MenuItemScreen(pgh){

}

TopGames::~TopGames(){

}

void TopGames::controller(){
    clear();
    mvprintw(4, 10, "Welcome to virtual world! Enjoy your time :)");
    int cmd = getch();
}
