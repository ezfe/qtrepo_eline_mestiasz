#ifndef WORMS_H
#define WORMS_H

#include "macros.h"

class Worms {
public:
    Worms();
    char set(int x, int y, char val);
    char get(int x, int y);
private:
    /*!
     * \brief Gameboard container
     *
     * Addressed in [x][y] manner
     */
    char gameboard[COLS][ROWS];
};

#endif // WORMS_H
