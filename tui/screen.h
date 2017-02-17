#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>
#include <curses.h>

#include "../engines/engine.h"

class Screen {
public:
    Screen();

    void init(Engine& engine);
    virtual void drawScreen(std::string str);

    bool continue_looping;
};

#endif // SCREEN_H
