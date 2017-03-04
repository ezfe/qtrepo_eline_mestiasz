#ifndef GAME_H
#define GAME_H

#include <string>

#include "player.h"

class Player;

class Game {
public:
    Game();
    Game(Player* player, std::string name, int score);
    ~Game();

    int get_score();
    std::string get_name();
    Player* get_player();

    int get_table_id() { return this->tableID; }
    int set_table_id(int id) { this->tableID = id; }
private:
    int score;
    std::string name;

    Player* player;

    int tableID;
};

#endif // GAME_H
