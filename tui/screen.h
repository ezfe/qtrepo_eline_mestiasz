#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>
#include <curses.h>

#include "../engines/engine.h"

class Screen {
public:
    Screen();
    ~Screen();

    void init();
    virtual void draw_screen(std::string str);

    bool continue_looping;

protected:
    Engine * engine;
};

#endif // SCREEN_H
