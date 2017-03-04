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
    virtual void init_form() = 0;

    bool continue_looping;

protected:
    FORM  *my_form;
};

#endif // MENUITEMSCREEN_H
