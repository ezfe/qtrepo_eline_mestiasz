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
    drawScreen(this->engine->printGameboard());
    do {
        refresh();
        int cmd = getch();
        drawScreen(std::to_string(cmd));
        if(cmd == 'q') break;

        std::string str = this->engine->controller(cmd);
        drawScreen(str);

    } while(continue_looping);

    endwin();

    std::cout << "exiting main\n";
}

void Screen::drawScreen(std::string str){
    clear();
    mvprintw(0, 0, "Welcome to the game! \n Enjoy your time :)");
}
