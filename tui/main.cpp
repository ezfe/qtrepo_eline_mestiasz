#include <iostream>

#include "robotsscreen.h"
#include "wormsscreen.h"
#include "menu.h"

using namespace std;

int main(int argc, char *argv[]) {

    Menu* menu = new Menu();
    menu->init();

    // Delete menu once the player quits the menu screen
    delete menu;

    return 0;

}
