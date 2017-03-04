#ifndef NEWPLAYER_H
#define NEWPLAYER_H

#include "menuitemscreen.h"

class NewPlayer : public MenuItemScreen{
public:
    NewPlayer(PlayerGameHistory* pgh);
    ~NewPlayer();

    void init_form();
    void submit_form();

private:
    FIELD *field[4];
    PlayerGameHistory* pgh;

};

#endif // NEWPLAYER_H
