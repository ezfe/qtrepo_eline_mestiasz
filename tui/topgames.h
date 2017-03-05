#ifndef TOPGAMES_H
#define TOPGAMES_H

#include <vector>

#include "menuitemscreen.h"

class TopGames : public MenuItemScreen{
public:
    TopGames(PlayerGameHistory* pgh);
    ~TopGames();

    void controller();
    std::vector<Game*> top_games();

};

#endif // TOPGAMES_H
