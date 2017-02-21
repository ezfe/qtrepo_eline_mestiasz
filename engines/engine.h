#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <string>
#include <sstream>

class Engine {
public:
    Engine(int rows, int cols);
    ~Engine();

    void set(int i, int j, char val);
    char get(int i, int j);
    void set_xy(int x, int y, char val);
    char get_xy(int x, int y);

    int get_width();
    int get_height();

    virtual std::string controller(char cmd) = 0;
    virtual std::string print_gameboard();

    virtual bool is_game_finished() = 0;
    virtual void reset_game() = 0;
    virtual int get_score() = 0;
protected:
    int ROWS = 4;
    int COLS = 4;

    char** gameboard;
};

#endif // ENGINE_H
