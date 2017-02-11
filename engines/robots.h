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

    /* Get information about the gameboard and its settlers */
    int getScore();                             // Getter for score counter
    int getLevel();                             // Getter for level counter
    bool isAlive();                             // Check if player is alive
    void setItem(int i, int j, char symbol);    //  Set item to provided value in gameboard container
    void setMoved(int i, int j, bool b);        //  Change bool value of the cell, once some object is placed in that cell
    char getItem(int i, int j);                 //  Get item from gameboard container
    bool ifMoved(int i, int j);                 //  Find if someone already moved to that cell
    std::vector<char> getOptions();             // Getter fot options container
    std::pair<int, int> getCurrentPosition();    // Getter for player's current position
    std::string printGameboard();               //  Print the gameboard, displaying all the robots and player
    std::pair<int, int> findEmptyCell();           //  Find empty cell, where player or robot can be placed

    /* Methods describing robot's behavior */
    void moveRobot(int i0, int j0, int i1, int j1);     //  Change the robots' locations
    void killRobot(int i, int j);                       //  Kill the robots
    std::vector<int> findCellToMove(int i, int j);      //  Find cell which is closest to the player,
                                                        //  so robots can catch player sooner
    /* Methods describing player's behavior */
    void move(int i0, int j0);  //  Move the player
    void doNothing();           //  Do not allow player do anything while it's possible
    void wait();                //  Make player wait until the end of the game
    void teleport();            //  Teleport the player
    void quit();                //  End the game
    void redraw();              //  Restart/Reinitialize the game
    int checkWinner();          //  Find if anybody lost already

    std::vector<int> generateRobotPosition();   //  Generate random positions for Robots
    std::vector<int> generatePlayerPosition();  //  Generate random position for Player

    void checkOptions();    //  Check which options were provided
    void showRanking();     //  Display the score list
    void jump();            //  Jump, do not show intermediate positions
    void playAutoMode();    //  Auto-bot mode


private:
    char gameboard [ROWS][COLS];            //  Gameboard container
    bool movedObjects [ROWS][COLS];         //  Displaying whether the object placed in that cell
                                            //  already changed the position or not
    std::vector<char> options;              //  List of options
    std::pair<int, int> currentPosition;    // Position of the player for the current time
    int score;                              //  Score counter
    int level;                              //  Level counter
    bool alive;                             //  Find if player is alive

};

#endif // ROBOTS_H
