#ifndef TOPPLAYERS_H
#define TOPPLAYERS_H

#include "algorithm"
#include "menuitemscreen.h"

class TopPlayers : public MenuItemScreen{
public:
    TopPlayers(PlayerGameHistory* pgh);
    ~TopPlayers();

    void controller();
    std::vector<Player*> top_players();

};

#endif // TOPPLAYERS_H
