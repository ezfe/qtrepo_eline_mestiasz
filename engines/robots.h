#ifndef ROBOTS_H
#define ROBOTS_H

#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <utility>

#include "engine.h"

class Robots: public Engine {
public:
    Robots(int rows, int cols, int robots);
    ~Robots();

    void setup_controller();
    std::string controller(char cmd);

    /* Get information about the gameboard and its settlers */
    void add_player_and_robots();                  //  Add player and robots to the gameboard at random location
    void init_moved_objects();                    //  Set each value in movedObjects container to false
    void set_item(int i, int j, char symbol);    //  Set item to provided value in gameboard container
    void set_moved(int i, int j, bool b);        //  Change bool value of the cell, once some object is placed in that cell
    void set_score(int score);                   //  Change score
    int get_score();                             //  Getter for score counter
    int get_level();                             //  Getter for level counter
    int check_winner();                          //  Find if anybody lost already
    bool if_moved(int i, int j);                 //  Find if someone already moved to that cell
    bool is_alive();                             //  Check if player is alive
    char get_item(int i, int j);                 //  Get item from gameboard container
    std::vector<char> get_options();             //  Getter fot options container
    std::pair<int, int> find_empty_cell();        //  Find empty cell, where player or robot can be placed

    /* Methods describing robot's behavior */
    void move_robot(int i0, int j0, int i1, int j1);     //  Change the robots' locations
    void move_each_robot();                               //  Change position for every robot
    void kill_robot(int i, int j);                       //  Kill the robots
    std::pair<int, int> find_cell_to_move(int i, int j);   //  Find cell which is closest to the player,
                                                        //  so robots can catch player sooner
    /* Methods describing player's behavior */
    void move(int i0, int j0);                  //  Move the player
    void teleport();                            //  Teleport the player
    void redraw();                              //  Restart/Reinitialize the game
    void die();                                 //  Set alive value to false
    void set_current_position(int i, int j);      //  Update player's position
    std::pair<int, int> get_current_position();   //  Getter for player's current position

    /* Methods that should be implemented in future */
    void check_options();                       //  Check which options were provided
    void show_ranking();                        //  Display the score list
    void jump();                                //  Jump, do not show intermediate positions
    void play_auto_mode();                      //  Auto-bot mode

    bool is_game_finished();
private:
    bool** movedObjects;                    //  Displaying whether the object placed in that cell
                                            //  already changed the position or not
    bool alive;                             //  Find if player is alive
    bool moved;                             //  Find if player moved
    int score;                              //  Score counter
    int level;                              //  Level counter
    std::vector<char> options;              //  List of options
    std::pair<int, int> currentPosition;    //  Position of the player for the current time

    int ROBOTS;
};

#endif // ROBOTS_H
