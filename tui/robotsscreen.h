#ifndef ROBOTSSCREEN_H
#define ROBOTSSCREEN_H

#include <iostream>
#include <string>

#include "../engines/robots.h"
#include "screen.h"

class RobotsScreen : public Screen{
public:
    RobotsScreen();

    void draw_screen(std::string str);

};

#endif // ROBOTSSCREEN_H
