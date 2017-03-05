#ifndef TOPPLAYERS_H
#define TOPPLAYERS_H

#include "menuitemscreen.h"

class TopPlayers : public MenuItemScreen{
public:
    TopPlayers(PlayerGameHistory* pgh);
    ~TopPlayers();

    void controller();

};

#endif // TOPPLAYERS_H
