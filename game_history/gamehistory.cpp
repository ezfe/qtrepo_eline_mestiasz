#include "gamehistory.h"

GameHistory::GameHistory() {

}

GameHistory::~GameHistory(){

}

void GameHistory::add_game(Game* game) {
    this->games.push_back(game);
}

std::vector<Game*> GameHistory::get_games(){
    std::cout << "Size == " << this->games.size() << std::endl;
    return this->games;
}
