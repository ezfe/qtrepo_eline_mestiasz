#include "statistics.h"

Statistics::Statistics(PlayerGameHistory* pgh) : MenuItemScreen(pgh) {

}

Statistics::~Statistics(){

}

void Statistics::controller(){
    clear();
    std::stringstream ss;

    mvprintw(1, 0, "Press q to exit!");
    mvprintw(3, 2, "Statistics:");
    mvprintw(4, 2, "-----------");

    ss << "  Number of games: "
       << this->pgh->number_games_played() << '\n'
       << "  Number of players: "
       << this->pgh->number_players_played() << '\n'
       << "  Top game score: "
       << this->pgh->top_game_score() << '\n'
       << "  Average number of games per player: "
       << this->pgh->avg_games_per_player() << '\n'
       << "  Average game score: "
       << std::to_string(this->pgh->avg_game_score()) << '\n';

    mvprintw(5, 0, ss.str().c_str());

    int cmd;
    do{
        cmd = getch();
    } while (cmd != 'q');

}
