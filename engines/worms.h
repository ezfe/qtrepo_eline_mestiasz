#ifndef WORMS_H
#define WORMS_H

#include "macros.h"

#include <iostream>
#include <vector>
#include <deque>

class Worms {
public:
    Worms();
    void set(int x, int y, char val);
    char get(int x, int y);

    void pressUp();
    void pressDown();
    void pressRight();
    void pressLeft();

    void placeGoal();

    std::vector<int> getHead();
    std::vector<int> getTail();
    void extendWorm();
    void trimWorm();
    int wormLength();
    int wormDataLength();
    std::vector<int> queryWorm(int i);

    bool isLost();
    int score();
private:
    /*!
     * \brief Gameboard container
     *
     * Addressed in [x][y] manner
     */
    char gameboard[WIDTH][HEIGHT];

    const char EMPTY_CELL = 'x';
    const char HEAD_CELL = '@';
    const char BODY_CELL = 'o';

    std::deque<std::vector<int>> path;

    int wormModify = 0;

    int random(int low, int high);
    int randomGoal();
    int randomX();
    int randomY();
    void move(int dx, int dy);

    bool gameOver = false;
};

#endif // WORMS_H
