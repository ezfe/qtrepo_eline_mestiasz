#include "wormsscreen.h"

WormsScreen::WormsScreen() : Screen(){
    this->engine = new Worms(50, 50);
}

void WormsScreen::drawScreen(std::string str){
    clear();
    mvprintw(0, 0, str.c_str());
}
