#include "menu.h"

Menu::Menu() : Screen(){
    pgh = new PlayerGameHistory();
//    pgh = new PlayerGameHistory(new DBTool("/Users/ezekielelin/Desktop/TestTableDB"));
    newPlayer = new NewPlayer(pgh);
    selectPlayer = new SelectPlayer(pgh);
    topPlayers = new TopPlayers(pgh);
    topGames = new TopGames(pgh);
    statistics = new Statistics(pgh);
    robots = new RobotsScreen(pgh);
    worms = new WormsScreen(pgh);

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

    mvprintw(0, 1, "Current Player: " );
    if(current_player == nullptr){
        mvprintw(0, 20, "No player selected / Select a player to start a game!" );
    } else {
        mvprintw(0, 20, current_player->get_first_name().c_str());
        mvprintw(1, 20, current_player->get_last_name().c_str());
    }
    mvprintw(3, 1, "a. Create a New Player");
    mvprintw(4, 1, "b. Select an Existing Player");
    mvprintw(6, 1, "c. Display Top Three Players");
    mvprintw(7, 1, "d. Display Top Three Games Played");
    mvprintw(8, 1, "e. Display Calculated Statistics");
    mvprintw(10, 1, "f. Play Robots");
    mvprintw(11, 1, "g. Play Worm");
    mvprintw(13, 1, "q. Exit Program");

}

void Menu::controller(char cmd){
    switch(cmd){
    case 'a':
        newPlayer->init();
        break;
    case 'b':
        selectPlayer->init();
        this->current_player = selectPlayer->get_player();
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
        if(this->current_player != nullptr)
            robots->init(this->current_player);
        break;
    case 'g':
        if(this->current_player != nullptr)
            worms->init(this->current_player);
        break;
    }
}
