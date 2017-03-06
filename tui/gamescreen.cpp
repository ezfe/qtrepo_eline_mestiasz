#include "gamescreen.h"

GameScreen::GameScreen(PlayerGameHistory* pgh){
    this->pgh = pgh;
    name = "Game";
}

GameScreen::~GameScreen(){
    delete engine;
}

/*!
 * \brief Initialize game screen and execute controller
 * \param player the current player
 */
void GameScreen::init(Player* player){
    this->player = player;

    continue_looping = true;
    draw_screen(this->engine->print_gameboard());

    do {
        refresh();
        int cmd = getch();
        // store game if it's redrawn or player quits
        if(cmd == 'q') {
            save_game();
            this->engine->reset_game();
            break;
        }else if(cmd == 'r'){
            save_game();
            this->engine->reset_game();
        }

        // call controller of the engine to execute a command
        std::string str = this->engine->controller(cmd);
        draw_screen(str);

    } while(continue_looping);

    std::cout << "exiting main\n";
}

/*!
 * \brief Store the game in PlayerGameHistory
 */
void GameScreen::save_game(){
    Game* game = new Game(this->player, this->name, this->engine->get_score());
    pgh->add_game(this->player, game);
}

/*!
 * \brief Redraw the screen
 * \param str String representation of the gameboard
 */
void GameScreen::draw_screen(std::string str){
    clear();
    mvprintw(0, 0, "Welcome to the game! \n Enjoy your time :)");
}
