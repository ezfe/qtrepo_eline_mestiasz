#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>
#include <curses.h>

class Screen {
public:
    Screen();
    ~Screen();

    void init();
    virtual void draw_screen();

    bool continue_looping;

};

#endif // SCREEN_H
