#ifndef WORMS_H
#define WORMS_H

#include "engine.h"

#include <iostream>
#include <vector>
#include <deque>

class Worms: public Engine {
public:
    Worms(int rows, int cols);
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
    const char EMPTY_CELL = 'x';
    const char HEAD_CELL = '@';
    const char BODY_CELL = 'o';

    /*!
     * \brief Data structure which stores points of the worm
     */
    std::deque<std::vector<int>> path;

    /*!
     * \brief Adjustments to worm size needed
     */
    int wormModify = 0;
    int scorePermanence = -1;

    int random(int low, int high);
    int randomGoal();
    int randomX();
    int randomY();
    void move(int dx, int dy);

    /*!
     * \brief Is the game over yet
     */
    bool gameOver = false;
};

#endif // WORMS_H
