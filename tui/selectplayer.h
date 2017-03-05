#ifndef SELECTPLAYER_H
#define SELECTPLAYER_H

#include "menuitemscreen.h"

class SelectPlayer : public MenuItemScreen{
public:
    SelectPlayer(PlayerGameHistory* pgh);
    ~SelectPlayer();

    void controller();
    Player* get_player();

private:
    Player* player;

};

#endif // SELECTPLAYER_H
