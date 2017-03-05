#include "topplayers.h"

TopPlayers::TopPlayers(PlayerGameHistory* pgh) : MenuItemScreen(pgh){

}

TopPlayers::~TopPlayers(){

}

void TopPlayers::controller(){
    clear();

    mvprintw(1, 0, "Press q to exit!");

    mvprintw(2, 5, "Firstname:");
    mvprintw(2, 20, "Lastname:");
    mvprintw(2, 35, "Score:");

    mvprintw(3, 5, "----------");
    mvprintw(3, 20, "---------");
    mvprintw(3, 35, "------");

    int i = 4;
    for(Player* player : pgh->get_players()){
        std::string num = std::to_string(i - 4);
        mvprintw(i, 0,  "#");
        mvprintw(i, 1,  num.c_str());
        mvprintw(i, 5,  player->get_first_name().c_str());
        mvprintw(i, 20, player->get_last_name().c_str());
        num = std::to_string(pgh->avg_score_per_player(player));
        mvprintw(i, 35, num.c_str());
        i++;
    }

    int cmd;
    do{
        cmd = getch();
    } while (cmd != 'q');
}
