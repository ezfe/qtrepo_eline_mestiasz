#ifndef WORMS_H
#define WORMS_H

#include "macros.h"

#include <iostream>

class Worms {
public:
    Worms();
    void set(int x, int y, char val);
    char get(int x, int y);

    void placeGoal();

    void pressUp();
    void pressDown();
    void pressRight();
    void pressLeft();
private:
    /*!
     * \brief Gameboard container
     *
     * Addressed in [x][y] manner
     */
    char gameboard[COLS][ROWS];
};

#endif // WORMS_H
