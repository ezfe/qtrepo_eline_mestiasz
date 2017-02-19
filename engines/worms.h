#ifndef WORMS_H
#define WORMS_H

#include "engine.h"

#include <iostream>
#include <vector>
#include <deque>

class Worms: public Engine {
public:
    Worms(int rows, int cols);

    std::string controller(char cmd);

    void press_up();
    void press_down();
    void press_right();
    void press_left();

    void place_goal();

    std::vector<int> get_head();
    std::vector<int> get_tail();
    void extend_worm();
    void trim_worm();
    int worm_length();
    int worm_data_length();
    std::vector<int> query_worm(int i);

    bool is_lost();
    int score();

    bool is_game_finished();
private:
    const char EMPTY_CELL = ' ';
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
    int random_goal();
    int random_x();
    int random_y();
    void move(int dx, int dy);

    /*!
     * \brief Is the game over yet
     */
    bool gameOver = false;

    /*!
     * \brief If an event happens, stop queued presses and return to regular gameplay
     */
    bool interruptQueuedPresses = false;
};

#endif // WORMS_H
