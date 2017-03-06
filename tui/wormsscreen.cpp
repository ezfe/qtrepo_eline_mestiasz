#include "wormsscreen.h"

WormsScreen::WormsScreen(PlayerGameHistory* pgh) : GameScreen(pgh){
    this->engine = new Worms(20, 20);
    this->name = "Worms";
}

WormsScreen::~WormsScreen(){

}

/*!
 * \brief Redraw the game screen
 * \param str String representation of the gameboard
 */
void WormsScreen::draw_screen(std::string str){
    clear();
    int starting_point = this->engine->get_width() + 10;
    mvprintw(0, 0, str.c_str());

    int row = 0;
    // print out the gameboard
    if (this->engine->is_game_finished()) {
        row += 2;
        mvprintw(0, starting_point, "Game Over:");
        mvprintw(1, starting_point, "Press q to exit");
    } else {
        mvprintw(0, starting_point, "Directions:" );
        mvprintw(2, starting_point, "  j");
        mvprintw(3, starting_point, "  |");
        mvprintw(4, starting_point, "h- -l");
        mvprintw(5, starting_point, "  |");
        mvprintw(6, starting_point, "  k");
        mvprintw(8, starting_point, "Hold shift to go further");
        mvprintw(10, starting_point, "Commands:");
        mvprintw(11, starting_point, "q: quit");
    }
}
