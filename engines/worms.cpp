#include "worms.h"

Worms::Worms(int rows, int cols): Engine(rows, cols) {

    std::srand(time(NULL));

    for(int x = 0; x < COLS; x++) {
        for(int y = 0; y < ROWS; y++) {
            set_xy(x, y, EMPTY_CELL);
        }
    }

    std::vector<int> pa {1, 1};
    std::vector<int> pb {2, 1};
    std::vector<int> pc {3, 1};
    path.push_back(pa);
    path.push_back(pb);
    path.push_back(pc);

    set_xy(pa[0], pa[1], BODY_CELL);
    set_xy(pb[0], pb[1], BODY_CELL);
    set_xy(pc[0], pc[1], HEAD_CELL);

    place_goal();
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
int Worms::random_goal() {
    return random(1, 9);
}

/*!
 * \brief Generate random x-position
 * \return x-position
 */
int Worms::random_x() {
    return random(0, COLS - 1);
}

/*!
 * \brief Generate random y-position
 * \return y-position
 */
int Worms::random_y() {
    return random(0, ROWS - 1);
}

/*!
 * \brief Place a goal of random value at a random location
 */
void Worms::place_goal() {
    while (true) {
        int x = random_x();
        int y = random_y();
        if (get_xy(x, y) == EMPTY_CELL) {
            set_xy(x, y, (char)(48 + random_goal()));
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
    interruptQueuedPresses = false;

    switch(cmd){
    case 'w':
        this->press_up();
        break;
    case 'a':
        this->press_left();
        break;
    case 'd':
        this->press_right();
        break;
    case 's':
        this->press_down();
        break;

    case 'j':
        this->press_up();
        break;
    case 'h':
        this->press_left();
        break;
    case 'l':
        this->press_right();
        break;
    case 'k':
        this->press_down();
        break;

    case 'J':
        for(int i = 0; i < 5; i++) {
            if (interruptQueuedPresses) {
                break;
            }
            this->press_up();
        }
        break;
    case 'H':
        for(int i = 0; i < 9; i++) {
            if (interruptQueuedPresses) {
                break;
            }
            this->press_left();
        }
        break;
    case 'L':
        for(int i = 0; i < 9; i++) {
            if (interruptQueuedPresses) {
                break;
            }
            this->press_right();
        }
        break;
    case 'K':
        for(int i = 0; i < 5; i++) {
            if (interruptQueuedPresses) {
                break;
            }
            this->press_down();
        }
        break;
    default:
        std::cout << "Invalid Command!" << std::endl;
    }

    return this->print_gameboard();
}

/*!
 * \brief Up arrow press or eq.
 */
void Worms::press_up() {
    move(0, -1);
}

/*!
 * \brief Down arrow press or eq.
 */
void Worms::press_down() {
    move(0, 1);
}

/*!
 * \brief Right arrow press or eq.
 */
void Worms::press_right() {
    move(1, 0);
}

/*!
 * \brief Left arrow press or eq.
 */
void Worms::press_left() {
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
    if (nx < 0 || ny < 0 || nx >= COLS || ny >= ROWS || get_xy(nx, ny) == 'o') {
        gameOver = true;
        scorePermanence = score();
        for(int i = 0; i < path.size(); i++) {
            set_xy(path[i][0], path[i][1], EMPTY_CELL);
        }
        path.clear();
        std::cout << "Collision, die" << std::endl;
    } else {
        /* Check for points */
        if (get_xy(nx, ny) == '1') {
            wormModify += 1;
            place_goal();
            interruptQueuedPresses = true;
        } else if (get_xy(nx, ny) == '2') {
            wormModify += 2;
            place_goal();
            interruptQueuedPresses = true;
        } else if (get_xy(nx, ny) == '3') {
            wormModify += 3;
            place_goal();
            interruptQueuedPresses = true;
        } else if (get_xy(nx, ny) == '4') {
            wormModify += 4;
            place_goal();
            interruptQueuedPresses = true;
        } else if (get_xy(nx, ny) == '5') {
            wormModify += 5;
            place_goal();
            interruptQueuedPresses = true;
        } else if (get_xy(nx, ny) == '6') {
            wormModify += 6;
            place_goal();
            interruptQueuedPresses = true;
        } else if (get_xy(nx, ny) == '7') {
            wormModify += 7;
            place_goal();
            interruptQueuedPresses = true;
        } else if (get_xy(nx, ny) == '8') {
            wormModify += 8;
            place_goal();
            interruptQueuedPresses = true;
        } else if (get_xy(nx, ny) == '9') {
            wormModify += 9;
            place_goal();
            interruptQueuedPresses = true;
        }

        /* Set the current head to a body */
        set_xy(hx, hy, BODY_CELL);
        /* Set the new head to a head */
        set_xy(nx, ny, HEAD_CELL);

        /* Push new head to the data structure */
        std::vector<int> hp {nx, ny};
        path.push_back(hp);

        /* trim last tail */
        wormModify--;

        /* Pop old tails */
        while(wormModify < 0) {
            std::vector<int> tp = path[0];
            path.pop_front();
            set_xy(tp[0], tp[1], EMPTY_CELL);
            wormModify++;
        }
    }
}

/*!
 * \brief Get head location
 * \return vector of location
 */
std::vector<int> Worms::get_head() {
    return path.back();
}

/*!
 * \brief Get tail location
 * \return vector of location
 */
std::vector<int> Worms::get_tail() {
    return path.front();
}

/*!
 * \brief Get location i
 * \param i index of worm
 * \return vector of location
 */
std::vector<int> Worms::query_worm(int i) {
    return path[i];
}

/*!
 * \brief Make the worm longer
 */
void Worms::extend_worm() {
    /* extension doesn't happen until next motion */
    wormModify++;
}

/*!
 * \brief Make the worm shorter
 */
void Worms::trim_worm() {
    /* trim doesn't happen until next motion */
    wormModify--;
}

/*!
 * \brief Get the actual worm length
 * \return worm length
 */
int Worms::worm_data_length() {
    return path.size();
}

/*!
 * \brief Get the expected worm length
 * \return worm length
 */
int Worms::worm_length() {
    return worm_data_length() + wormModify;
}

/*!
 * \brief Check if the game is over
 * \return game over
 */
bool Worms::is_lost() {
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
    return worm_length();
}

/*!
 * \brief Check if the game is over
 * \return game over
 */
bool Worms::is_game_finished() {
    return is_lost();
}

/*!
 * \brief Reset this game
 */
void Worms::reset_game() {

}
