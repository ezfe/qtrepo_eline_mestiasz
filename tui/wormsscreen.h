#ifndef WORMSSCREEN_H
#define WORMSSCREEN_H

#include <iostream>
#include <string>

#include "../engines/worms.h"
#include "gamescreen.h"

class WormsScreen : public GameScreen{
public:
    WormsScreen();

    void draw_screen(std::string str);

};

#endif // WORMSSCREEN_H
