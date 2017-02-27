#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>

#include "screen.h"
#include "newplayer.h"

class Menu : public Screen{
public:
    Menu();
    ~Menu();

    void draw_screen();
    void controller(char cmd);
};

#endif // MENU_H
