#ifndef PLAYERGAMEHISTORY_H
#define PLAYERGAMEHISTORY_H

#include "player.h"

class PlayerGameHistory {
public:
    PlayerGameHistory();

    int number_games_played();
    int number_players_played();
    int average_games_per_player();
    int top_game_score();
    int avg_game_score();
    int avg_game_score_player(Player p);
private:

};

#endif // PLAYERGAMEHISTORY_H
