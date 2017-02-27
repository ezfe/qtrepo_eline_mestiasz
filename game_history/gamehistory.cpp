#include "gamehistory.h"

GameHistory::GameHistory() {

}

GameHistory::~GameHistory(){

}

void GameHistory::add_game(Game* game) {
    this->games.push_back(game);
}

std::vector<Game*> GameHistory::get_games(){
    return this->games;
}

int GameHistory::get_total_score(){
    int totalScore = 0;
    for(auto game : games){
        totalScore += game->get_score();
    }
    return totalScore;
}
