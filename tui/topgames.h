#ifndef TOPGAMES_H
#define TOPGAMES_H

#include "menuitemscreen.h"

class TopGames : public MenuItemScreen{
public:
    TopGames(PlayerGameHistory* pgh);
    ~TopGames();

    void controller();

private:
    PlayerGameHistory* pgh;
};

#endif // TOPGAMES_H
