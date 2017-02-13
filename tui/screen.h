#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>
#include <curses.h>

class Screen {
public:
    Screen();

    void init();
    void drawScreen();

    bool continue_looping;
};

#endif // SCREEN_H
