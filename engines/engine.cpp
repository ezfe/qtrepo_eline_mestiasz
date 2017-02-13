#include "engine.h"

Engine::Engine() {
    gameboard = new char*[ROWS];
    for(int i = 0; i < ROWS; i++) {
        gameboard[i] = new char[COLS];
    }

    for(int j = 0; j < ROWS; j++) {
        for(int i = 0; i < COLS; i++) {
            gameboard[i][j] = '_';
        }
    }
}

Engine::~Engine() {
    // What to do here?
}
