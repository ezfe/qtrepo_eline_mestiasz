#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include "game.h"
#include "gamehistory.h"

class Game;
class GameHistory;

class Player {
public:
    Player();
    Player(std::string first_name, std::string last_name, std::string address);

    void add_game(Game* game);

    std::string get_first_name();
    std::string get_last_name();
    std::string get_address();
    Game* get_recent_game();
    GameHistory* get_games();

private:
    std::string firstName;
    std::string lastName;
    std::string address;

    Game* recentGame;
    GameHistory* games;

};

#endif // PLAYER_H
