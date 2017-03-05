#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <iostream>
#include <string>
#include <curses.h>

#include "../engines/engine.h"
#include "../game_history/playergamehistory.h"

class GameScreen {
public:
    GameScreen(PlayerGameHistory* pgh);
    virtual ~GameScreen();

    void init(Player* player);
    void save_game();
    virtual void draw_screen(std::string str);

    bool continue_looping;

protected:
    Engine * engine;
    PlayerGameHistory* pgh;
    Player* player;
};

#endif // SCREEN_H
