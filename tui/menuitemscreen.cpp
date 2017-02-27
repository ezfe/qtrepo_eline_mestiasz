#include "menuitemscreen.h"

MenuItemScreen::MenuItemScreen(){

}

MenuItemScreen::~MenuItemScreen(){

}

void MenuItemScreen::init(){
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

        draw_screen();

    } while(continue_looping);

    endwin();

    std::cout << "exiting main\n";
}

void MenuItemScreen::draw_screen(){
    clear();
    mvprintw(0, 0, "Welcome to the game! \n Enjoy your time :)");
}
