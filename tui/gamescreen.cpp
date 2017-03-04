#include "gamescreen.h"

GameScreen::GameScreen(){

}

GameScreen::~GameScreen(){
    delete engine;
}

void GameScreen::init(){

    continue_looping = true;
    draw_screen(this->engine->print_gameboard());

    do {
        refresh();
        int cmd = getch();
        if(cmd == 'q') {
            this->engine->reset_game();
            break;
        }

        std::string str = this->engine->controller(cmd);
        draw_screen(str);

    } while(continue_looping);

    std::cout << "exiting main\n";
}

void GameScreen::draw_screen(std::string str){
    clear();
    mvprintw(0, 0, "Welcome to the game! \n Enjoy your time :)");
}
