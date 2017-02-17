#include "robotsscreen.h"

RobotsScreen::RobotsScreen(): Screen(){
    this->engine = new Robots(50, 50, 10);
}

void RobotsScreen::drawScreen(std::string str){
    clear();
    mvprintw(0, 0, str.c_str());
}
