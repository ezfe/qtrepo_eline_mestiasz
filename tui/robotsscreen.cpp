#include "robotsscreen.h"

RobotsScreen::RobotsScreen(PlayerGameHistory* pgh): GameScreen(pgh){
    this->engine = new Robots(20, 50, 10);
}

RobotsScreen::~RobotsScreen(){

}

void RobotsScreen::draw_screen(std::string str){
    clear();
    int starting_point = this->engine->get_width() + 10;
    mvprintw(0, 0, str.c_str());

    mvprintw(0, starting_point, "Directions:" );
    mvprintw(2, starting_point, "y k u");
    mvprintw(3, starting_point, "\\ | /");
    mvprintw(4, starting_point, "h- -l");
    mvprintw(5, starting_point, "/ | \\");
    mvprintw(6, starting_point, "b j n");
    mvprintw(8, starting_point, "Commands:");
    mvprintw(10, starting_point, "w: wait for end");
    mvprintw(11, starting_point, "t: teleport");
    mvprintw(12, starting_point, "q: quit");
    mvprintw(13, starting_point, "r: restart");
    mvprintw(15, starting_point, "Legend:");
    mvprintw(17, starting_point, "+: robot");
    mvprintw(18, starting_point, "*: junk heap");
    mvprintw(19, starting_point, "@: player");

}
