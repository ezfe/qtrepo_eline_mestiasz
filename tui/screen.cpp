#include "screen.h"

Screen::Screen(){

}

void Screen::init(Engine& engine){
    initscr();
    curs_set(0);

    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    continue_looping = true;
    drawScreen(engine.controller('p'));

    do {
        refresh();
        int cmd = getch();

        if(cmd == 'q') break;

        std::string str = engine.controller(cmd);
        drawScreen(str);

    } while(continue_looping);

    endwin();

    std::cout << "exiting main\n";
}

void Screen::drawScreen(std::string str){
    clear();
    mvprintw(0, 0, "Welcome to the game! \n Enjoy your time :)");
}
