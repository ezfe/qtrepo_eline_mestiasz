#ifndef MENUITEMSCREEN_H
#define MENUITEMSCREEN_H

#include <form.h>
#include <iostream>
#include <string>

#include "../game_history/playergamehistory.h"

class MenuItemScreen {
public:
    MenuItemScreen();
    virtual ~MenuItemScreen();

    void init();
    virtual void init_form() = 0;
    virtual void submit_form() = 0;

    bool continue_looping;

protected:
    FORM  *my_form;
};

#endif // MENUITEMSCREEN_H
