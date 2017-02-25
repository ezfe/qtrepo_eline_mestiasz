#ifndef GAME_H
#define GAME_H

#include <string>

#include "player.h"

class Player;

class Game {
public:
    Game();
    Game(Player* player, std::string name, int score);

    int get_score();
    std::string get_name();
    Player* get_player();


private:
    int score;
    std::string name;

    Player* player;
};

#endif // GAME_H
