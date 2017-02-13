#include "worms.h"
#include "robots.h"
#include "engine.h"

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

    Worms worms(10, 10);
    Robots robots(10, 10, 7);
    robots.setupController();

    return 0;

}
