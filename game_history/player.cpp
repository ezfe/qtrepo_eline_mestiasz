#include "player.h"

Player::Player(std::string first_name, std::string last_name, std::string address) {
    this->first_name = first_name;
    this->last_name = last_name;
    this->address = address;
}

Player::Player() {
    this->first_name = "John";
    this->last_name = "Appleseed";
    this->address = "111 Quad Dr";
}
