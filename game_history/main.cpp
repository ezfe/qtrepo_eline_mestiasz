#include <iostream>

#include "dbtool.h"
#include "playergamehistory.h"
#include "player.h"
#include "game.h"

using namespace std;

int main(int argc, char *argv[]) {
    PlayerGameHistory* playerGameHistory = new PlayerGameHistory();

    Player* player = new Player("Mr", "Anderson", "Matrix");
    Game* game = new Game(player, "robots", 11);
    playerGameHistory->add_game(player, game);

    game = new Game(player, "robots", 1);
    playerGameHistory->add_game(player, game);

    player = new Player("Miss", "Rogbeer", "17");
    game = new Game(player, "worms", 11);
    playerGameHistory->add_game(player, game);

    game = new Game(player, "robots", 1);
    playerGameHistory->add_game(player, game);

    delete playerGameHistory;
}
