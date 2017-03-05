#include "selectplayer.h"

SelectPlayer::SelectPlayer(PlayerGameHistory* pgh) : MenuItemScreen(pgh){

}

SelectPlayer::~SelectPlayer(){

}

void SelectPlayer::controller(){
    clear();
    mvprintw(4, 10, "Welcome to virtual world! Enjoy your time :)");
    int cmd = getch();
}

