#ifndef SELECTPLAYER_H
#define SELECTPLAYER_H

#include "menuitemscreen.h"

class SelectPlayer : public MenuItemScreen{
public:
    SelectPlayer(PlayerGameHistory* pgh);
    ~SelectPlayer();

    void controller();

private:
    PlayerGameHistory* pgh;

};

#endif // SELECTPLAYER_H
