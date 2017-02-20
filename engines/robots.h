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
    void add_player_and_robots();
    void init_moved_objects();
    void set_item(int i, int j, char symbol);
    void set_moved(int i, int j, bool b);
    void set_score(int score);
    int get_score();
    int get_level();
    int check_winner();
    bool if_moved(int i, int j);
    bool is_alive();
    bool check_cell(int i, int j);
    bool is_game_finished();
    char get_item(int i, int j);
    std::pair<int, int> find_empty_cell();

    /* Methods describing robot's behavior */
    void move_robot(int i0, int j0, int i1, int j1);
    void move_each_robot();
    void kill_robot(int i, int j);
    std::pair<int, int> find_cell_to_move(int i, int j);

    /* Methods describing player's behavior */
    void move(int i0, int j0);
    void teleport();
    void redraw();
    void die();
    void set_current_position(int i, int j);
    std::pair<int, int> get_current_position();

private:
    //  Displaying whether the object placed in that cell
    //  already changed the position or not
    bool** movedObjects;
    //  Find if player is alive
    bool alive;
    //  Find if player moved
    bool moved;
    //  Score counter
    int score;
    //  Level counter
    int level;
    //  Position of the player for the current time
    std::pair<int, int> currentPosition;

    int ROBOTS;
};

#endif // ROBOTS_H
