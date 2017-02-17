#include "robotsscreen.h"

RobotsScreen::RobotsScreen(): Screen(){
    this->engine = new Robots(10, 10, 10);
}

void RobotsScreen::drawScreen(std::string str){
    clear();
    mvprintw(0, 0, str.c_str());
}
