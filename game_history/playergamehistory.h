#ifndef PLAYERGAMEHISTORY_H
#define PLAYERGAMEHISTORY_H

#include <vector>

#include "game.h"
#include "player.h"

class PlayerGameHistory {
public:
    PlayerGameHistory();
    ~PlayerGameHistory();

    int number_games_played();
    int number_players_played();
    int top_game_score();
    double avg_games_per_player();
    double avg_score_per_player(Player* player);
    double avg_game_score();

    void add_game(Player* player, Game* game);

private:
    std::vector<Player*> players;
    std::vector<Game*> games;

};

#endif // PLAYERGAMEHISTORY_H
