#include <iostream>

#include "robotsscreen.h"
#include "wormsscreen.h"

using namespace std;

int main(int argc, char *argv[]) {

    RobotsScreen screen_01;
    WormsScreen screen_02;

    std::cout << "Choose your game:" << std::endl;
    std::cout << "Type 1 to play Robots" << std::endl;
    std::cout << "Type 2 to play Worms" << std::endl;


    char cmd;
    while(std::cin >> cmd){
        switch(cmd){
        case '1':
            screen_01.init();
            break;
        case '2':
            screen_02.init();
            break;
        default:
            std::cout << "Type the number of the game you want to play" << std::endl;
        }

        std::cout << "Choose your game:" << std::endl;
        std::cout << "Type 1 to play Robots" << std::endl;
        std::cout << "Type 2 to play Worms" << std::endl;

    }


    return 0;

}
