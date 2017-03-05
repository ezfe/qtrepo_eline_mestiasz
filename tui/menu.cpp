#include "menu.h"

Menu::Menu() : Screen(){
    pgh = new PlayerGameHistory();
    newPlayer = new NewPlayer(pgh);
    selectPlayer = new SelectPlayer();
    topPlayers = new TopPlayers();
    topGames = new TopGames();
    statistics = new Statistics();
    robots = new RobotsScreen();
    worms = new WormsScreen();

}

Menu::~Menu(){
    std::cout << "~Menu" << std::endl;
    delete newPlayer;
    delete selectPlayer;
    delete topPlayers;
    delete topGames;
    delete statistics;
    delete robots;
    delete worms;
    delete pgh;
    std::cout << "~Menu" << std::endl;
}

void Menu::draw_screen(){
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

    if(pgh->get_players().size() != 0){
        mvprintw(14, 1, pgh->get_players().at(0)->get_first_name().c_str());
        mvprintw(15, 1, pgh->get_players().at(0)->get_last_name().c_str());
        mvprintw(16, 1, pgh->get_players().at(0)->get_address().c_str());
    }
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
