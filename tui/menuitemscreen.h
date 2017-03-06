#ifndef MENUITEMSCREEN_H
#define MENUITEMSCREEN_H

#include <form.h>
#include <iostream>
#include <string>

#include "../game_history/playergamehistory.h"

class MenuItemScreen {
public:
    MenuItemScreen(PlayerGameHistory* pgh);
    virtual ~MenuItemScreen();

    void init();
    virtual void controller() = 0;


protected:
    PlayerGameHistory* pgh;
    bool continue_looping;
};

#endif // MENUITEMSCREEN_H
