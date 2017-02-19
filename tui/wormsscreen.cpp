#include "wormsscreen.h"

WormsScreen::WormsScreen() : Screen(){
    this->engine = new Worms(20, 20);
}

void WormsScreen::draw_screen(std::string str){
    clear();
    if (this->engine->is_game_finished()) {
        mvprintw(0, 0, "Game Over. Press q to exit...");
        mvprintw(1, 0, str.c_str());
    } else {
        mvprintw(0, 0, str.c_str());
    }
}
