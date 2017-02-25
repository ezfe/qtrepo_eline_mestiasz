#include "game.h"

/*!
 * \brief Create a name with a name and a score
 * \param name of the game
 * \param score of the game
 */
Game::Game(Player* player, std::string name, int score) {
    this->name = name;
    this->score = score;
    this->player = player;
}

/*!
 * \brief Create a game
 */
Game::Game() {
    this->name = "";
    this->score = 0;
}

Game::~Game(){
    // delete player;
    // as player has this, and this has player, one of them is
    // destructied earlier and calls destructor of the other one while
    // that one is already destructed
}

/*!
 * \brief Get the name of the game
 * \return game name
 */
std::string Game::get_name() {
    return this->name;
}

/*!
 * \brief Get the score of the game
 * \return game score
 */
int Game::get_score() {
    return this->score;
}

Player* Game::get_player(){
    return this->player;
}
