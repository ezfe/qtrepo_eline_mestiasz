#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>

class Engine {
public:
    Engine();
    ~Engine();

protected:
    const int ROWS = 4;
    const int COLS = 4;

    char** gameboard;
};

#endif // ENGINE_H
