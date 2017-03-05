#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>

#include "../game_history/playergamehistory.h"
#include "screen.h"
#include "newplayer.h"
#include "selectplayer.h"
#include "topgames.h"
#include "topplayers.h"
#include "statistics.h"
#include "robotsscreen.h"
#include "wormsscreen.h"

class Menu : public Screen{
public:
    Menu();
    ~Menu();

    void draw_screen();
    void controller(char cmd);

private:
    NewPlayer* newPlayer;
    SelectPlayer* selectPlayer;
    TopPlayers* topPlayers;
    TopGames* topGames;
    Statistics* statistics;
    RobotsScreen* robots;
    WormsScreen* worms;
    PlayerGameHistory* pgh;
};

#endif // MENU_H
