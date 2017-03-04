#include "menu.h"

Menu::Menu() : Screen(){
    newPlayer = new NewPlayer();
    selectPlayer = new SelectPlayer();
    topPlayers = new TopPlayers();
    topGames = new TopGames();
    statistics = new Statistics();
    robots = new RobotsScreen();
    worms = new WormsScreen();
}

Menu::~Menu(){
    delete newPlayer;
    delete selectPlayer;
    delete topPlayers;
    delete topGames;
    delete statistics;
    delete robots;
    delete worms;
}

void Menu::draw_screen(){
    std::cout << "yeap" << std::endl;
    clear();

    mvprintw(0, 1, "Current Player: No player selected" );
    mvprintw(2, 1, "a. Create a New Player");
    mvprintw(3, 1, "b. Select an Existing Player");
    mvprintw(5, 1, "c. Display Top Three Players");
    mvprintw(6, 1, "d. Display Top Three Games Played");
    mvprintw(7, 1, "e. Display Calculated Statistics");
    mvprintw(9, 1, "f. Play Robots");
    mvprintw(10, 1, "g. Play Worm");
    mvprintw(12, 1, "q. Exit Program");
}

void Menu::controller(char cmd){
    switch(cmd){
    case 'a':
        newPlayer->init();
        break;
    case 'b':
        selectPlayer->init();
        break;
    case 'c':
        topPlayers->init();
        break;
    case 'd':
        topGames->init();
        break;
    case 'e':
        statistics->init();
        break;
    case 'f':
        robots->init();
        break;
    case 'g':
        worms->init();
        break;
    }
}
