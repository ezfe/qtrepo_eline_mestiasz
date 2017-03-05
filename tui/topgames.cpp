#include "topgames.h"

TopGames::TopGames(PlayerGameHistory* pgh) : MenuItemScreen(pgh){

}

TopGames::~TopGames(){

}

void TopGames::controller(){
    clear();

    mvprintw(1, 0, "Press q to exit!");

    mvprintw(2, 5, "Game:");
    mvprintw(2, 20, "Firstname:");
    mvprintw(2, 35, "Lastname:");
    mvprintw(2, 50, "Score:");

    mvprintw(3, 5, "-----");
    mvprintw(3, 20, "----------");
    mvprintw(3, 35, "---------");
    mvprintw(3, 50, "------");

    int i = 4;
    for(Game* game : pgh->get_games()){
        std::string num = std::to_string(i - 4);
        mvprintw(i, 0,  "#");
        mvprintw(i, 1,  num.c_str());
        mvprintw(i, 5,  game->get_name().c_str());
        mvprintw(i, 20, game->get_player()->get_first_name().c_str());
        mvprintw(i, 35, game->get_player()->get_last_name().c_str());
        num = std::to_string(game->get_score());
        mvprintw(i, 50, num.c_str());
        i++;
    }

    int cmd;
    do{
        cmd = getch();
    } while (cmd != 'q');

}
