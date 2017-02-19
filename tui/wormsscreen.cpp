#include "wormsscreen.h"

WormsScreen::WormsScreen() : Screen(){
    this->engine = new Worms(20, 20);
}

void WormsScreen::draw_screen(std::string str){
    clear();
    mvprintw(0, 0, str.c_str());
}
