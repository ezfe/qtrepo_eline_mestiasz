#ifndef NEWPLAYER_H
#define NEWPLAYER_H

#include "menuitemscreen.h"

class NewPlayer : public MenuItemScreen{
public:
    NewPlayer(PlayerGameHistory* pgh);
    ~NewPlayer();

    void init_form();
    void controller();
    void submit_form();

private:
    FORM* my_form;
    FIELD* field[4];
    PlayerGameHistory* pgh;

};

#endif // NEWPLAYER_H
