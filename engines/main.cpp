#include "robots.h"
#include "engine.h"
#include "../tui/screen.h"

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

    Screen screen;
    Robots robots(10, 10, 7);
    screen.init(robots);

    return 0;

}
