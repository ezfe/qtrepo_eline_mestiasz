#include "engine.h"

Engine::Engine(int rows, int cols) {
    ROWS = rows;
    COLS = cols;

    gameboard = new char*[ROWS];
    for(int i = 0; i < ROWS; i++) {
        gameboard[i] = new char[COLS];
    }

    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
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
    if (gameboard && gameboard[i]) {
        gameboard[i][j] = val;
    } else {
        std::cout << "No gameboard found..." << std::endl;
    }
}

/*!
 * \brief Set gameboard value
 * \param x location
 * \param y location
 * \param val value to set
 */
void Engine::set_xy(int x, int y, char val) {
    return set(y, x, val);
}

/*!
 * \brief Get the gameboard value
 * \param y location
 * \param x location
 * \return
 */
char Engine::get(int i, int j) {
    if (gameboard && gameboard[i]) {
        return gameboard[i][j];
    } else {
        /* hmm */
        std::cout << "No gameboard found..." << std::endl;
        return ' ';
    }
}

/*!
 * \brief Get the gameboard value
 * \param x location
 * \param y location
 * \return value at location
 */
char Engine::get_xy(int x, int y) {
    return get(y, x);
}

int Engine::get_width() {
    return COLS;
}

int Engine::get_height() {
    return ROWS;
}

/*!
 * \brief Display the gameboard
 * \return Gameboard - std::string
 */
std::string Engine::print_gameboard(){
    std::stringstream ss;

    for(int i = 0; i <= COLS + 1; i++){
        ss << "#";
    }
    ss << std::endl;

    for(int i = 0; i < ROWS; i++){
        ss << "#";
        for(int j = 0; j < COLS; j++){
            ss << this->get(i, j);
        }
        ss << "#" << std::endl;
    }

    for(int i = 0; i <= COLS + 1; i++){
        ss << "#";
    }
    ss << std::endl;

    return ss.str();
}
