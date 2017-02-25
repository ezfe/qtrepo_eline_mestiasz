#ifndef GAMEHISTORY_H
#define GAMEHISTORY_H

#include <vector>

class GameHistory {
public:
    GameHistory();

private:
    std::vector<Player*> players;
};

#endif // GAMEHISTORY_H
