#include "gamehistory.h"

GameHistory::GameHistory() {
    this->games.clear();
}

GameHistory::~GameHistory(){
    for(auto game : this->games){
        delete game;
    }
}

/*!
 * \brief Add a game
 * \param game to add
 */
void GameHistory::add_game(Game* game) {
    this->games.push_back(game);
}

/*!
 * \brief Get the games
 * \return std::vector<Game*> games
 */
std::vector<Game*> GameHistory::get_games(){
    return this->games;
}

/*!
 * \brief Get the total score of all the games
 * \return int total score
 */
int GameHistory::get_total_score(){
    int totalScore = 0;
    for(auto game : games){
        totalScore += game->get_score();
    }
    return totalScore;
}
