#include "worms.h"

Worms::Worms() {
    std::srand(time(NULL));

    for(int x = 0; x < WIDTH; x++) {
        for(int y = 0; y < HEIGHT; y++) {
            set(x, y, EMPTY_CELL);
        }
    }

    std::vector<int> pa {1, 1};
    std::vector<int> pb {2, 1};
    path.push_back(pa);
    path.push_back(pb);

    set(pa[0], pa[1], BODY_CELL);
    set(pb[0], pb[1], HEAD_CELL);
}

/*!
 * \brief Set gameboard value
 * \param x location
 * \param y location
 * \param val value to set
 */
void Worms::set(int x, int y, char val) {
    gameboard[x][y] = val;
}

char Worms::get(int x, int y) {
    return gameboard[x][y];
}

/*!
 * \brief Generate random number
 * \param low value (inclusive)
 * \param high value (inclusive)
 * \return random number
 */
int Worms::random(int low, int high) {
    return std::rand() % (high - low) + low; //low-high
}

/*!
 * \brief Generate random goal-value
 * \return goal-value
 */
int Worms::randomGoal() {
    return random(1, 9);
}

/*!
 * \brief Generate random x-position
 * \return x-position
 */
int Worms::randomX() {
    return random(0, COLS - 1);
}

/*!
 * \brief Generate random y-position
 * \return y-position
 */
int Worms::randomY() {
    return random(0, ROWS - 1);
}

void Worms::placeGoal() {
    std::cout << "Placing goal..." << std::endl;
    int x = randomX();
    int y = randomY();
    gameboard[x][y] = (char)(48 + randomGoal());
}

void Worms::pressUp() {
    move(0, -1);
}

void Worms::pressDown() {
    move(0, 1);
}

void Worms::pressRight() {
    move(1, 0);
}

void Worms::pressLeft() {
    move(-1, 0);
}

void Worms::move(int dx, int dy) {
    int hx = path.back()[0];
    int hy = path.back()[1];
    int nx = hx + dx;
    int ny = hy + dy;
    if (nx < 0 || ny < 0 || nx >= COLS || ny >= ROWS || get(nx, ny) == 'o') {
        std::cout << "Collision, die" << std::endl;
    } else {
        set(hx, hy, BODY_CELL);
        set(nx, ny, HEAD_CELL);

        /* Push new head */
        std::vector<int> hp {nx, ny};
        path.push_back(hp);

        /* Pop old tail */
        std::vector<int> tp = path[0];
        path.pop_front();
        set(tp[0], tp[1], 'x');
    }
    /*else if (get(nx, ny) != '\0') {
        int val = ((int)get(nx, ny)) - 48;
        std::cout << "Grow " + val << std::endl;
    }*/

}

std::vector<int> Worms::getHead() {
    return path.back();
}
