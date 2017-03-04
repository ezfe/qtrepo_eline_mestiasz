#ifndef PLAYERGAMEHISTORY_H
#define PLAYERGAMEHISTORY_H

#include <vector>

#include "game.h"
#include "player.h"
#include "dbtool.h"
#include "dbtableplayers.h"
#include "dbtablegames.h"

class PlayerGameHistory {
public:
    PlayerGameHistory();
    PlayerGameHistory(DBTool* dbtool);
    ~PlayerGameHistory();

    int number_games_played();
    int number_players_played();
    int top_game_score();
    double avg_games_per_player();
    double avg_score_per_player(Player* player);
    double avg_game_score();
    std::vector<Player*> get_players();
    std::vector<Game*> get_games();

    void add_game(Player* player, Game* game);
    void add_player(std::string f, std::string l, std::string a);

private:
    std::vector<Player*> players;
    std::vector<Game*> games;

    int get_valid_table_id();

    DBTool* db = nullptr;
};

#endif // PLAYERGAMEHISTORY_H
