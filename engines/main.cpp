#include "worms.h"
#include "robots.h"
#include "macros.h"

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    Worms w;

    w.placeGoal();


    for(int i = 0; i < 5; i++) {
        for(int y = 0; y < HEIGHT; y++){
            std::cout << "|";
            for(int x = 0; x < WIDTH; x++){
                char c = w.get(x, y);
                if (c == 'x') {
                    c = ' ';
                }
                std::cout << c;
            }
            std::cout << "|" << std::endl;
        }
        for(int x = 0; x < WIDTH; x++){
            std::cout << "-";
        }
        std::cout << std::endl;

        w.pressRight();
    }

    return 0;
}
