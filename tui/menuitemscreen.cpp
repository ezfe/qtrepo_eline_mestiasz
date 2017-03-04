#include "menuitemscreen.h"

MenuItemScreen::MenuItemScreen(){

}

MenuItemScreen::~MenuItemScreen(){

}

void MenuItemScreen::init(){

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

    std::cout << "exiting main\n";
}

void MenuItemScreen::draw_screen(){
    clear();
    mvprintw(0, 0, "Welcome to the game! \n Enjoy your time :)");
}
