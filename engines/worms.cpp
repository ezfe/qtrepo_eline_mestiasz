#include "worms.h"

Worms::Worms() {

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

void Worms::get(int x, int y) {
    return gameboard[x][y];
}
