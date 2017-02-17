#include "worms.h"

Worms::Worms(int rows, int cols): Engine(rows, cols) {

    std::srand(time(NULL));

    for(int x = 0; x < COLS; x++) {
        for(int y = 0; y < ROWS; y++) {
            setXY(x, y, EMPTY_CELL);
        }
    }

    std::vector<int> pa {1, 1};
    std::vector<int> pb {2, 1};
    std::vector<int> pc {3, 1};
    path.push_back(pa);
    path.push_back(pb);
    path.push_back(pc);

    setXY(pa[0], pa[1], BODY_CELL);
    setXY(pb[0], pb[1], BODY_CELL);
    setXY(pc[0], pc[1], HEAD_CELL);

    placeGoal();
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

/*!
 * \brief Place a goal of random value at a random location
 */
void Worms::placeGoal() {
    std::cout << "Placing goal..." << std::endl;
    while (true) {
        int x = randomX();
        int y = randomY();
        if (getXY(x, y) == EMPTY_CELL) {
            setXY(x, y, (char)(48 + randomGoal()));
            break;
        }
    }
}

/*!
 * \brief Send char inputs
 * \param cmd character pressed
 * \return gameboard state
 */
std::string Worms::controller(char cmd){
    switch(cmd){
    case 'w':
        this->pressUp();
        break;
    case 'a':
        this->pressLeft();
        break;
    case 'd':
        this->pressRight();
        break;
    case 's':
        this->pressDown();
        break;
    default:
        std::cout << "Invalid Command!" << std::endl;
    }

    return this->printGameboard();
}

/*!
 * \brief Up arrow press or eq.
 */
void Worms::pressUp() {
    move(0, -1);
}

/*!
 * \brief Down arrow press or eq.
 */
void Worms::pressDown() {
    move(0, 1);
}

/*!
 * \brief Right arrow press or eq.
 */
void Worms::pressRight() {
    move(1, 0);
}

/*!
 * \brief Left arrow press or eq.
 */
void Worms::pressLeft() {
    move(-1, 0);
}

/*!
 * \brief Move the worm in an x/y direction.
 * \param dx delta x direction
 * \param dy delta y direction
 *
 * Values above 1 may cause issues and discontinuous worms. The worm
 * should still move there, however.
 */
void Worms::move(int dx, int dy) {
    if (gameOver) {
        return;
    }
    /* Find the head x/y */
    int hx = path.back()[0];
    int hy = path.back()[1];
    /* Find the new location for the head */
    int nx = hx + dx;
    int ny = hy + dy;
    /* If the new location is out of game board, or part of the worm, exit */
    if (nx < 0 || ny < 0 || nx >= COLS || ny >= ROWS || getXY(nx, ny) == 'o') {
        gameOver = true;
        scorePermanence = score();
        for(int i = 0; i < path.size(); i++) {
            setXY(path[i][0], path[i][1], EMPTY_CELL);
        }
        path.clear();
        std::cout << "Collision, die" << std::endl;
    } else {
        /* Check for points */
        if (getXY(nx, ny) == '1') {
            wormModify += 1;
            placeGoal();
        } else if (getXY(nx, ny) == '2') {
            wormModify += 2;
            placeGoal();
        } else if (getXY(nx, ny) == '3') {
            wormModify += 3;
            placeGoal();
        } else if (getXY(nx, ny) == '4') {
            wormModify += 4;
            placeGoal();
        } else if (getXY(nx, ny) == '5') {
            wormModify += 5;
            placeGoal();
        } else if (getXY(nx, ny) == '6') {
            wormModify += 6;
            placeGoal();
        } else if (getXY(nx, ny) == '7') {
            wormModify += 7;
            placeGoal();
        } else if (getXY(nx, ny) == '8') {
            wormModify += 8;
            placeGoal();
        } else if (getXY(nx, ny) == '9') {
            wormModify += 9;
            placeGoal();
        }

        /* Set the current head to a body */
        setXY(hx, hy, BODY_CELL);
        /* Set the new head to a head */
        setXY(nx, ny, HEAD_CELL);

        /* Push new head to the data structure */
        std::vector<int> hp {nx, ny};
        path.push_back(hp);

        /* trim last tail */
        wormModify--;

        /* Pop old tails */
        while(wormModify < 0) {
            std::vector<int> tp = path[0];
            path.pop_front();
            setXY(tp[0], tp[1], EMPTY_CELL);
            wormModify++;
        }
    }
}

/*!
 * \brief Get head location
 * \return vector of location
 */
std::vector<int> Worms::getHead() {
    return path.back();
}

/*!
 * \brief Get tail location
 * \return vector of location
 */
std::vector<int> Worms::getTail() {
    return path.front();
}

/*!
 * \brief Get location i
 * \param i index of worm
 * \return vector of location
 */
std::vector<int> Worms::queryWorm(int i) {
    return path[i];
}

/*!
 * \brief Make the worm longer
 */
void Worms::extendWorm() {
    /* extension doesn't happen until next motion */
    wormModify++;
}

/*!
 * \brief Make the worm shorter
 */
void Worms::trimWorm() {
    /* trim doesn't happen until next motion */
    wormModify--;
}

/*!
 * \brief Get the actual worm length
 * \return worm length
 */
int Worms::wormDataLength() {
    return path.size();
}

/*!
 * \brief Get the expected worm length
 * \return worm length
 */
int Worms::wormLength() {
    return wormDataLength() + wormModify;
}

/*!
 * \brief Check if the game is over
 * \return game over
 */
bool Worms::isLost() {
    return gameOver;
}

/*!
 * \brief Query the score
 * \return score
 */
int Worms::score() {
    if (scorePermanence != -1) {
        return scorePermanence;
    }
    return wormLength();
}

/*!
 * \brief Check if the game is over
 * \return game over
 */
bool Worms::isGameFinished() {
    return isLost();
}
