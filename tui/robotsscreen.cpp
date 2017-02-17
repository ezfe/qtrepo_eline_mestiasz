#include "robotsscreen.h"

RobotsScreen::RobotsScreen(){

}

RobotsScreen::drawScreen(std::string str){
    clear();
    mvprintw(0, 0, "Welcome to the game! \n DON'T Enjoy your time :)");
}
