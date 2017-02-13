#include "screen.h"

Screen::Screen(){

}

void Screen::init(std::function<void(char)> controller){
    initscr();
    curs_set(0);

    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    continue_looping = true;
    drawScreen();

    do {
        refresh();
        int cmd = getch();

        controller(cmd);
        draw_screen(v);

    } while(continue_looping);

    endwin();

    std::cout << "exiting main\n";
    return 0;
}

void Screen::drawScreen(){

    std::string display;
    clear();

    mvprintw(2, 4, "Current Value : ");
    display = "11";
    mvprintw(2, 21, display.c_str());

    // print the instructions for manipulating the Value object
    mvprintw(5, 4, "Up Arrow    : increments value");
    mvprintw(6, 4, "Down Arrow  : decrements value");
    mvprintw(7, 4, "Left Arrow  : resets value to zero");
    mvprintw(8, 4, "Right Arrow : exits program");
}
