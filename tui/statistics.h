#ifndef STATISTICS_H
#define STATISTICS_H

#include "menuitemscreen.h"

class Statistics : public MenuItemScreen {
public:
    Statistics(PlayerGameHistory* pgh);
    ~Statistics();

    void controller();
private:
    PlayerGameHistory* pgh;
};

#endif // STATISTICS_H
