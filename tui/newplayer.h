#ifndef NEWPLAYER_H
#define NEWPLAYER_H

#include "menuitemscreen.h"

class NewPlayer : public MenuItemScreen{
public:
    NewPlayer();
    ~NewPlayer();

    void init_form();

private:
    FIELD *field[3];

};

#endif // NEWPLAYER_H
