#ifndef STATISTICS_H
#define STATISTICS_H

#include <iostream>
#include <string>
#include <sstream>

#include "menuitemscreen.h"

class Statistics : public MenuItemScreen {
public:
    Statistics(PlayerGameHistory* pgh);
    ~Statistics();

    void controller();

};

#endif // STATISTICS_H
