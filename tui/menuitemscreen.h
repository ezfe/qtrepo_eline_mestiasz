#ifndef MENUITEMSCREEN_H
#define MENUITEMSCREEN_H

#include <form.h>
#include <iostream>
#include <string>

class MenuItemScreen {
public:
    MenuItemScreen();
    ~MenuItemScreen();

    void init();
    virtual void draw_screen();

    bool continue_looping;
};

#endif // MENUITEMSCREEN_H
