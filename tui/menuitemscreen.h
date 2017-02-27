#ifndef MENUITEMSCREEN_H
#define MENUITEMSCREEN_H

#include <curses.h>
#include <iostream>

class MenuItemScreen {
public:
    MenuItemScreen();
    ~MenuItemScreen();

    void init();
    virtual void draw_screen();

    bool continue_looping;
};

#endif // MENUITEMSCREEN_H
