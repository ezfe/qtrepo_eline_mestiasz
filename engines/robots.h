#ifndef ROBOTS_H
#define ROBOTS_H

#include <iostream>
#include <string>
#include <vector>

#include "macros.h"


class Robots {
public:
    Robots();
    ~Robots();

    void addItem(char symbol);
    void setItem(char symbol, int index);
    char getItem(int index);

    void moveRobots(); // Change the robots' locations
    void killRobot();

    void move();
    void doNothing();
    void wait();
    void teleport();
    void quit();
    void redraw();
    bool checkWinner();

    void checkOptions();
    void showRanking();
    void jump();
    void playAutoMode();



private:
    char gameboard [ROWS][COLS];
    std::vector<char> options;
    int score;
    int level;
    bool alive;
};

#endif // ROBOTS_H
