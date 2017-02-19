#include "robotsscreen.h"

RobotsScreen::RobotsScreen(): Screen(){
    this->engine = new Robots(20, 20, 10);
}

void RobotsScreen::draw_screen(std::string str){
    clear();
    mvprintw(0, 0, str.c_str());
}
