#include "player.h"

Player::Player(std::string firstName, std::string lastName, std::string address) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->address = address;

    this->games = new GameHistory();
    this->recentGame = nullptr;
}

Player::Player() {
    this->firstName = "";
    this->lastName = "";
    this->address = "";

    this->games = new GameHistory();
    this->recentGame = nullptr;
}

Player::~Player() {
    delete games;
    delete recentGame;
}

/*!
 * \brief Add a game to this player
 * \param g game to add
 */
void Player::add_game(Game* g) {
    if(recentGame != nullptr) this->games->add_game(recentGame);
    this->recentGame = g;
}

/*!
 * \brief Get the total score for this player (all games, summed).
 * \return int total score
 */
int Player::get_total_score(){
    if(recentGame == nullptr) return 0;
    return games->get_total_score() + recentGame->get_score();
}

/*!
 * \brief Get the player's first name
 * \return std::string first name
 */
std::string Player::get_first_name(){
    return this->firstName;
}

/*!
 * \brief Get the player's last name
 * \return std::string last name
 */
std::string Player::get_last_name(){
    return this->lastName;
}

/*!
 * \brief Get the player's address
 * \return std::string address
 */
std::string Player::get_address(){
    return this->address;
}

/*!
 * \brief Get the last game played
 * \return Game* last game played
 */
Game* Player::get_recent_game(){
    return this->recentGame;
}

/*!
 * \brief Get the other games
 * \return GameHistory* other games
 */
GameHistory* Player::get_game_history(){
    return this->games;
}
