#include "gamehistory.h"

GameHistory::GameHistory() {
    this->games.clear();
}

GameHistory::~GameHistory(){
    this->games.clear();
}

void GameHistory::add_game(Game* game) {
    this->games.push_back(game);
}

std::vector<Game*> GameHistory::get_games(){
    return this->games;
}
