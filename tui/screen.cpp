#include "screen.h"

Screen::Screen(){

}

Screen::~Screen(){
    delete engine;
}

void Screen::init(){
    initscr();
    curs_set(0);

    cbreak();
    noecho();
    keypad(stdscr, TRUE);

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

    endwin();

    std::cout << "exiting main\n";
}

void Screen::draw_screen(std::string str){
    clear();
    mvprintw(0, 0, "Welcome to the game! \n Enjoy your time :)");
}
