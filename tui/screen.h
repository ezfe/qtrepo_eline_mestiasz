#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>
#include <curses.h>

class Screen {
public:
    Screen();

    void init(std::function<void(char)> controller);
    void drawScreen();

    bool continue_looping;
};

#endif // SCREEN_H
