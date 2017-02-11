#include "worms.h"
#include "robots.h"
#include "macros.h"

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    Worms w;

    w.placeGoal();

    for(int x = 0; x < COLS; x++){
        for(int y = 0; y < ROWS; y++){
            char c = w.get(x, y);
            if (c == '\0') {
                c = ' ';
            }
            std::cout << c;
        }
        std::cout << std::endl;
    }

    return 0;
}
