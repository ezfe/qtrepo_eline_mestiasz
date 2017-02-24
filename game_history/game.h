#ifndef GAME_H
#define GAME_H

#include <string>
#include "player.h"

class Game {
public:
    Game(Player player, std::string name, int score);
    Game();

    std::string get_name();
    int get_score();
private:
    std::string name;
    int score;
    Player* player;
};

#endif // GAME_H
