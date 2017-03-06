#include "screen.h"

Screen::Screen(){

}

Screen::~Screen(){

}

/*!
 * \brief Initialize ncurses
 */
void Screen::init(){
    initscr();
    curs_set(0);

    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    continue_looping = true;
    draw_screen();

    do {
        refresh();
        int cmd = getch();

        if(cmd == 'q') {
            break;
        }
        // execute the command
        this->controller(cmd);
        draw_screen();

    } while(continue_looping);

    endwin();

    std::cout << "exiting main\n";
}

void Screen::draw_screen(){
    clear();
    mvprintw(0, 0, "Welcome to the game! \n Enjoy your time :)");
}
