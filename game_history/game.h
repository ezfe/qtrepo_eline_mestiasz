#ifndef GAME_H
#define GAME_H

#include <string>

class Game {
public:
    Game(std::string name, int score);
    Game();

    std::string get_name();
    int get_score();
private:
    std::string name;
    int score;
};

#endif // GAME_H
