#ifndef NEWPLAYER_H
#define NEWPLAYER_H

#include "menuitemscreen.h"

class NewPlayer : public MenuItemScreen{
public:
    NewPlayer();
    ~NewPlayer();

    void draw_screen();

private:
    FIELD *field[3];
    FORM  *myForm;
    int ch;
};

#endif // NEWPLAYER_H
