#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>

#include "screen.h"

class Menu : public Screen{
public:
    Menu();
    ~Menu();

    void draw_screen();
};

#endif // MENU_H
