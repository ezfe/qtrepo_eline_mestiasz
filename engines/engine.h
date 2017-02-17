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
    void setXY(int x, int y, char val);
    char getXY(int x, int y);

    int getWidth();
    int getHeight();

    std::string printGameboard();
protected:
    int ROWS = 4;
    int COLS = 4;

    char** gameboard;
};

#endif // ENGINE_H
