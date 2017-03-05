#include "selectplayer.h"

SelectPlayer::SelectPlayer(PlayerGameHistory* pgh) : MenuItemScreen(pgh){

}

SelectPlayer::~SelectPlayer(){

}

void SelectPlayer::controller(){
    clear();
    mvprintw(2, 5, "Firstname:");
    mvprintw(2, 20, "Lastname:");
    mvprintw(2, 35, "Address:");

    mvprintw(3, 5, "----------");
    mvprintw(3, 20, "---------");
    mvprintw(3, 35, "--------");

    int i = 4;
    for(Player* player : pgh->get_players()){
        std::string num = std::to_string(i - 4);
        mvprintw(i, 0,  "#");
        mvprintw(i, 1,  num.c_str());
        mvprintw(i, 5,  player->get_first_name().c_str());
        mvprintw(i, 20, player->get_last_name().c_str());
        mvprintw(i, 35, player->get_address().c_str());
        i++;
    }
    int cmd = getch();
    //z/ check once more
    if(cmd >= 48 && cmd < (48 + pgh->get_players().size())){
        player = pgh->get_players().at(cmd - 48);
    }
}

Player* SelectPlayer::get_player(){
    return this->player;
}
