#ifndef PLAYERGAMEHISTORY_H
#define PLAYERGAMEHISTORY_H

#include <vector>

class PlayerGameHistory {
public:
    PlayerGameHistory();

private:
    std::vector<Player*> players;
};

#endif // PLAYERGAMEHISTORY_H
