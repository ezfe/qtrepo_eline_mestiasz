#include "worms.h"

Worms::Worms() {
    std::srand(time(NULL));
}

/*!
 * \brief Set gameboard value
 * \param x location
 * \param y location
 * \param val value to set
 */
void Worms::set(int x, int y, char val) {
    gameboard[x][y] = val;
}

char Worms::get(int x, int y) {
    return gameboard[x][y];
}

void Worms::placeGoal() {
    int n = std::rand() % 8 + 1; //1-9
    std::cout << n << std::endl;
}
