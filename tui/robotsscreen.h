#ifndef ROBOTSSCREEN_H
#define ROBOTSSCREEN_H

#include <iostream>
#include <string>

#include "../engines/robots.h"
#include "gamescreen.h"

class RobotsScreen : public GameScreen{
public:
    RobotsScreen();

    void draw_screen(std::string str);

};

#endif // ROBOTSSCREEN_H
