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

void Player::add_game(Game* g) {
    this->games->add_game(g);
    this->recentGame = g;
}

std::string Player::get_first_name(){
    return this->firstName;
}

std::string Player::get_last_name(){
    return this->lastName;
}

std::string Player::get_address(){
    return this->address;
}

Game* Player::get_recent_game(){
    return this->recentGame;
}

GameHistory* Player::get_games(){
    return this->games;
}
