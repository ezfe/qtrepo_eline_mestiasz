#ifndef SELECTPLAYER_H
#define SELECTPLAYER_H

#include "menuitemscreen.h"

class SelectPlayer : public MenuItemScreen{
public:
    SelectPlayer();
    ~SelectPlayer();

    void init_form();

private:
    FIELD *field[3];
};

#endif // SELECTPLAYER_H
