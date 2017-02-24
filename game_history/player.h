#ifndef PLAYER_H
#define PLAYER_H

#include "string"
#include "game.h"
#include "gamehistory.h"

class Player {
public:
    Player(std::string first_name, std::string last_name, std::string address);
    Player();

private:
    Game most_recent_game;
    GameHistory games;

    std::string first_name;
    std::string last_name;
    std::string address;
};

#endif // PLAYER_H
