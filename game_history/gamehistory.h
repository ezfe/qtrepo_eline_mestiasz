#ifndef GAMEHISTORY_H
#define GAMEHISTORY_H

#include <vector>
#include <iostream>

#include "game.h"
class Game;

class GameHistory {
public:
    GameHistory();
    ~GameHistory();

    void add_game(Game* game);

    std::vector<Game*> get_games();

private:
    std::vector<Game*> games;

};

#endif // GAMEHISTORY_H
