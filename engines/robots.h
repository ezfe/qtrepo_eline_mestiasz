#ifndef ROBOTS_H
#define ROBOTS_H

#include <iostream>
#include <ctime>
#include <string>
#include <vector>

#include "macros.h"


class Robots {
public:
    Robots();
    ~Robots();

    void addItem(char symbol);              //  Add item to gameboard container
    void setItem(int i, int j, char symbol);   //  Set item to provided value in gameboard container
    char getItem(int i, int j);             //  Get item from gameboard container
    std::string printGameboard();           //  Print the gameboard, displaying all the robots and player

    void moveRobot();      //  Change the robots' locations
    void killRobot();       //  Kill the robots

    void move();            //  Move the player
    void doNothing();       //  Do not allow player do anything while it's possible
    void wait();            //  Make player wait until the end of the game
    void teleport();        //  Teleport the player
    void quit();            //  End the game
    void redraw();          //  Restart/Reinitialize the game
    bool checkWinner();     //  Find if anybody lost already

    void generateRobotPosition();   //  Generate random positions for Robots
    void generatePlayerPosition();  //  Generate random position for Player

    void checkOptions();    //  Check which options were provided
    void showRanking();     //  Display the score list
    void jump();            //  Jump, do not show intermediate positions
    void playAutoMode();    //  Auto-bot mode

    std::vector<char> getOptions(); // Getter fot options container
    int getScore();                 // Getter for score counter
    int getLevel();                 // Getter for level counter
    bool isAlive();                 // Check if player is alive


private:
    char gameboard [ROWS][COLS];    //  Gameboard container
    std::vector<char> options;      //  List of options
    int score;                      //  Score counter
    int level;                      // Level counter
    bool alive;
};

#endif // ROBOTS_H