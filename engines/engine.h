#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>

class Engine {
public:
    Engine(int rows, int cols);
    ~Engine();

    void set(int x, int y, char val);
    char get(int x, int y);

    int getWidth();
    int getHeight();
protected:
    int ROWS = 4;
    int COLS = 4;

    char** gameboard;
};

#endif // ENGINE_H
