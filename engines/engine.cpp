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
            gameboard[i][j] = ' ';
        }
    }
}

Engine::~Engine() {
    // What to do here?
}

/*!
 * \brief Set gameboard value
 * \param y location
 * \param x location
 * \param val value to set
 */
void Engine::set(int i, int j, char val) {
    gameboard[i][j] = val;
}

/*!
 * \brief Set gameboard value
 * \param x location
 * \param y location
 * \param val value to set
 */
void Engine::setXY(int x, int y, char val) {
    gameboard[y][x] = val;
}

/*!
 * \brief Get the gameboard value
 * \param y location
 * \param x location
 * \return
 */
char Engine::get(int i, int j) {
    return gameboard[i][j];
}

/*!
 * \brief Get the gameboard value
 * \param x location
 * \param y location
 * \return value at location
 */
char Engine::getXY(int x, int y) {
    return gameboard[y][x];
}

int Engine::getWidth() {
    return COLS;
}

int Engine::getHeight() {
    return ROWS;
}

/*!
 * \brief Display the gameboard
 * \return Gameboard - std::string
 */
std::string Engine::printGameboard(){
    std::stringstream ss;
    for(int i = 0; i < ROWS; i++){
        ss << "#" << i << ":   ";
        for(int j = 0; j < COLS; j++){
            ss << this->get(i, j);
        }
        ss << std::endl;
    }

    return ss.str();
}
