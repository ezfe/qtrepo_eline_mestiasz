#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <iostream>
#include <string>
#include <curses.h>

#include "../engines/engine.h"

class GameScreen {
public:
    GameScreen();
    ~GameScreen();

    void init();
    virtual void draw_screen(std::string str);

    bool continue_looping;

protected:
    Engine * engine;
};

#endif // SCREEN_H
