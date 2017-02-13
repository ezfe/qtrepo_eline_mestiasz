#include "engine.h"

Engine::Engine(int rows, int cols) {
    ROWS = rows;
    COLS = cols;

    gameboard = new char*[ROWS];
    for(int i = 0; i < ROWS; i++) {
        gameboard[i] = new char[COLS];
    }

    for(int j = 0; j < ROWS; j++) {
        for(int i = 0; i < COLS; i++) {
            gameboard[i][j] = '_';
        }
    }
}

Engine::~Engine() {
    // What to do here?
}

/*!
 * \brief Set gameboard value
 * \param x location
 * \param y location
 * \param val value to set
 */
void Engine::set(int x, int y, char val) {
    gameboard[x][y] = val;
}

/*!
 * \brief Get the gameboard value
 * \param x location
 * \param y location
 * \return value at location
 */
char Engine::get(int x, int y) {
    return gameboard[x][y];
}
