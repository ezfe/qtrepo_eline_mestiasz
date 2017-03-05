#include "gamescreen.h"

GameScreen::GameScreen(PlayerGameHistory* pgh){
    this->pgh = pgh;
    name = "Game";
}

GameScreen::~GameScreen(){
    delete engine;
}

void GameScreen::init(Player* player){
    this->player = player;

    continue_looping = true;
    draw_screen(this->engine->print_gameboard());

    do {
        refresh();
        int cmd = getch();
        if(cmd == 'q') {
            save_game();
            this->engine->reset_game();
            break;
        }else if(cmd == 'r'){
            save_game();
            this->engine->reset_game();
        }


        std::string str = this->engine->controller(cmd);
        draw_screen(str);

    } while(continue_looping);

    std::cout << "exiting main\n";
}

void GameScreen::save_game(){
    Game* game = new Game(this->player, this->name, this->engine->get_score());
    pgh->add_game(this->player, game);
}

void GameScreen::draw_screen(std::string str){
    clear();
    mvprintw(0, 0, "Welcome to the game! \n Enjoy your time :)");
}
