#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>

class Engine {
public:
    Engine(int rows, int cols);
    ~Engine();

protected:
    int ROWS = 4;
    int COLS = 4;

    char** gameboard;
};

#endif // ENGINE_H
