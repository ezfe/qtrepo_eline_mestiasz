#ifndef ROBOTS_H
#define ROBOTS_H

#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <sstream>
#include <utility>

#include "macros.h"


class Robots {
public:
    Robots();
    ~Robots();

    void setupController();

    /* Get information about the gameboard and its settlers */
    void addPlayerAndRobots();                  //  Add player and robots to the gameboard at random location
    void initMovedObjects();                    //  Set each value in movedObjects container to false
    void setItem(int i, int j, char symbol);    //  Set item to provided value in gameboard container
    void setMoved(int i, int j, bool b);        //  Change bool value of the cell, once some object is placed in that cell
    void setScore(int score);                   //  Change score
    int getScore();                             //  Getter for score counter
    int getLevel();                             //  Getter for level counter
    int checkWinner();                          //  Find if anybody lost already
    bool ifMoved(int i, int j);                 //  Find if someone already moved to that cell
    bool isAlive();                             //  Check if player is alive
    char getItem(int i, int j);                 //  Get item from gameboard container
    std::vector<char> getOptions();             //  Getter fot options container
    std::string printGameboard();               //  Print the gameboard, displaying all the robots and player
    std::pair<int, int> findEmptyCell();        //  Find empty cell, where player or robot can be placed

    /* Methods describing robot's behavior */
    void moveRobot(int i0, int j0, int i1, int j1);     //  Change the robots' locations
    void moveEachRobot();                               //  Change position for every robot
    void killRobot(int i, int j);                       //  Kill the robots
    std::pair<int, int> findCellToMove(int i, int j);   //  Find cell which is closest to the player,
                                                        //  so robots can catch player sooner
    /* Methods describing player's behavior */
    void move(int i0, int j0);                  //  Move the player
    void doNothing();                           //  Do not allow player do anything while it's possible
    void wait();                                //  Make player wait until the end of the game
    void teleport();                            //  Teleport the player
    void redraw();                              //  Restart/Reinitialize the game
    void die();                                 //  Set alive value to false
    void setCurrentPosition(int i, int j);      //  Update player's position
    std::pair<int, int> getCurrentPosition();   //  Getter for player's current position

    /* Methods that should be implemented in future */
    void checkOptions();                        //  Check which options were provided
    void showRanking();                         //  Display the score list
    void jump();                                //  Jump, do not show intermediate positions
    void playAutoMode();                        //  Auto-bot mode


private:
    char gameboard [ROWS][COLS];            //  Gameboard container
    bool movedObjects [ROWS][COLS];         //  Displaying whether the object placed in that cell
                                            //  already changed the position or not
    bool alive;                             //  Find if player is alive
    int score;                              //  Score counter
    int level;                              //  Level counter
    std::vector<char> options;              //  List of options
    std::pair<int, int> currentPosition;    //  Position of the player for the current time

};

#endif // ROBOTS_H
