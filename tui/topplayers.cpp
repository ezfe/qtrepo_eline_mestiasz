#include "topplayers.h"

TopPlayers::TopPlayers(PlayerGameHistory* pgh) : MenuItemScreen(pgh){

}

TopPlayers::~TopPlayers(){

}

/*!
 * \brief Setup controller for TopPlayers
 */
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
    for(Player* player : top_players()){
        if(i > 6) break;
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

/*!
 * \brief Sort the players container
 * \return top vector of sorted players
 */
std::vector<Player*> TopPlayers::top_players(){
    std::vector<Player*> top = pgh->get_players();
    struct {
       bool operator()(Player* a, Player* b){
           int tmpA = a->get_game_history()->get_games().size();
           if(tmpA == 0) return 0;
           int tmpB = b->get_game_history()->get_games().size();
           if(tmpB == 0) return 1;
           return (a->get_total_score()/tmpA) >
                  (b->get_total_score()/tmpB);
       }
    } playerComparator;
    std::sort(top.begin(), top.end(), playerComparator);
    return top;
}
