#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>
#include <curses.h>

#include "../engines/robots.h"

class Screen {
public:
    Screen();

    void init(Robots& robots);
    void drawScreen(std::string str);

    bool continue_looping;
};

#endif // SCREEN_H
