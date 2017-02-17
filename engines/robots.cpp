#include "robots.h"

Robots::Robots(int rows, int cols, int robots): Engine(rows, cols) {

    movedObjects = new bool*[rows];
    for(int i = 0; i < rows; i++) {
        movedObjects[i] = new bool[cols];
    }

    for(int j = 0; j < rows; j++) {
        for(int i = 0; i < cols; i++) {
            movedObjects[i][j] = false;
        }
    }

    this->redraw();
    this->addPlayerAndRobots();
    this->ROBOTS = robots;
}

Robots::~Robots(){

}

/* Controller */
/*!
 * \brief The method initializes controller, which takes user
 * input and performs certain commands.
 */
void Robots::setupController(){
    char cmd;
    std::cout << "Insert a command" << std::endl;

    std::pair<int, int> current_position;
    // Stay in program and exectute commands until the new command is 'q'
    // The commands are the same as the ones for the provided game, only ^L
    // is different - in this case this command is 'r'
    // the controller also decides where the player will move next
    while(std::cin >> cmd){
        current_position = this->getCurrentPosition();
        switch(cmd){
        case 'q':
            exit(0);
            break;
        case 'w':
            while(this->checkWinner() == 0){
                this->moveEachRobot();
                std::cout << printGameboard() << std::endl;
            }
            break;
        case 't':
            this->teleport();
            break;
        case 'r':
            this->redraw();
            this->addPlayerAndRobots();
            break;
        case 'y':
            this->move(current_position.first - 1, current_position.second - 1);
            this->moveEachRobot();
            break;
        case 'k':
            this->move(current_position.first - 1, current_position.second);
            this->moveEachRobot();
            break;
        case 'u':
            this->move(current_position.first - 1, current_position.second + 1);
            this->moveEachRobot();
            break;
        case 'h':
            this->move(current_position.first, current_position.second - 1);
            this->moveEachRobot();
            break;
        case 'l':
            this->move(current_position.first, current_position.second + 1);
            this->moveEachRobot();
            break;
        case 'b':
            this->move(current_position.first + 1, current_position.second - 1);
            this->moveEachRobot();
            break;
        case 'j':
            this->move(current_position.first + 1, current_position.second);
            this->moveEachRobot();
            break;
        case 'n':
            this->move(current_position.first + 1, current_position.second + 1);
            this->moveEachRobot();
            break;
        default:
            std::cout << "Invalid Command!" << std::endl;
        }

        std::cout << this->printGameboard();
        // Check if there is winner, if so start new game and display the final score
        if(this->checkWinner() != 0){
            std::cout << "Score: " << this->getScore() << std::endl << std::endl << std::endl;
            this->redraw();
            this->addPlayerAndRobots();
            std::cout << this->printGameboard();
        }
        std::cout << "Insert a command" << std::endl;
    }
}


std::string Robots::controller(char cmd){
    std::pair<int, int> current_position = this->getCurrentPosition();
    switch(cmd){
    case 'w':
        while(this->checkWinner() == 0){
            this->moveEachRobot();
        }
        break;
    case 't':
        this->teleport();
        break;
    case 'r':
        this->redraw();
        this->addPlayerAndRobots();
        break;
    case 'y':
        this->move(current_position.first - 1, current_position.second - 1);
        this->moveEachRobot();
        break;
    case 'k':
        this->move(current_position.first - 1, current_position.second);
        this->moveEachRobot();
        break;
    case 'u':
        this->move(current_position.first - 1, current_position.second + 1);
        this->moveEachRobot();
        break;
    case 'h':
        this->move(current_position.first, current_position.second - 1);
        this->moveEachRobot();
        break;
    case 'l':
        this->move(current_position.first, current_position.second + 1);
        this->moveEachRobot();
        break;
    case 'b':
        this->move(current_position.first + 1, current_position.second - 1);
        this->moveEachRobot();
        break;
    case 'j':
        this->move(current_position.first + 1, current_position.second);
        this->moveEachRobot();
        break;
    case 'n':
        this->move(current_position.first + 1, current_position.second + 1);
        this->moveEachRobot();
        break;
    }

    // Check if there is winner, if so start new game and display the final score
    if(this->checkWinner() != 0){
        std::stringstream game_over;
        game_over << "Score: " << this->getScore() << std::endl << std::endl << std::endl;
        this->redraw();
        this->addPlayerAndRobots();
        game_over << "------- New Game -------" << std::endl << this->printGameboard();
        return game_over.str();
    }

    return this->printGameboard();

}

/* Gameboard */
/*!
 * \brief Get the score
 * \return Current score - int
 */
int Robots::getScore(){
    return this->score;
}

/*!
 * \brief Get the level
 * \return current level - int
 */
int Robots::getLevel(){
    return this->level;
}

/*!
 * \brief Find if player is alive
 * \return Alive - bool
 */
bool Robots::isAlive(){
    return this->alive;
}

/*!
 * \brief Get the cell valeu from gameboard
 * \param i - index of ROW
 * \param j - index of COL
 * \return The symbolt from gameboard - char
 */
char Robots::getItem(int i, int j){
    return get(i, j);
}

/*!
 * \brief Find if robot has moved already
 * \param i - index of ROW
 * \param j - index of COL
 * \return Moved - bool
 */
bool Robots::ifMoved(int i, int j){
    return this->movedObjects[i][j];
}

/*!
 * \brief Find if someone won already
 * \return winner - 0 - not yet, 1 - player, 2 - robots won
 */
int Robots::checkWinner(){
    int counter_of_robots = 0;
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            if(this->getItem(i, j) == '+')
                counter_of_robots++;
        }
    }

    // If player is alive and there are robots game continues
    if(isAlive() && counter_of_robots != 0) return 0;
    // If player is alive and there are no robots player wins
    if(isAlive() && counter_of_robots == 0) return 1;

    return 2;
}

/*!
 * \brief Get options container
 * \return Options - std::vector<char>
 */
std::vector<char> Robots::getOptions(){
    return this->options;
}

/*!
 * \brief Find empty cell where player or robot can be
 * positioned in the begining of the game
 * \return Position - std::pair<int, int>
 */
std::pair<int, int> Robots::findEmptyCell(){
    std::vector<std::pair<int, int>> empty_cells;
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            if(this->getItem(i, j) == ' '){
                empty_cells.push_back(std::make_pair(i, j));
            }
        }
    }

    // if there are empty cells generate random position
    if(empty_cells.size() != 0){
        int index = rand() % empty_cells.size();
        return empty_cells.at(index);
    }

    return std::make_pair(-1, -1);
}

/*!
 * \brief Change value of the cell
 * \param i - index of ROW
 * \param j - index of COL
 * \param symbol - value that we want to set
 */
void Robots::setItem(int i, int j, char symbol){
    set(i, j, symbol);
    if(symbol == '@') this->setCurrentPosition(i, j);
}

/*!
 * \brief Change bool value of the cell
 * \param i - index of ROW
 * \param j - index of COL
 * \param b - value that we want to set
 */
void Robots::setMoved(int i, int j, bool b){
    movedObjects[i][j] = b;
}

/*!
 * \brief Change value of the cell
 * \param score - new score
 */
void Robots::setScore(int score){
    this->score = score;
}

/*!
 * \brief Add players and robots to the gameboard
 */
void Robots::addPlayerAndRobots(){
    std::pair<int, int> empty_cell;
    for(int i = 0; i < ROWS; i++){
        empty_cell = findEmptyCell();
        this->setItem(empty_cell.first, empty_cell.second, '+');
    }

    // Finally add the player to the gameboard
    empty_cell = findEmptyCell();
    this->setItem(empty_cell.first, empty_cell.second, '@');
}

/*!
 * \brief Set bool value of every cell to false, so
 * the robots can move again
 */
void Robots::initMovedObjects(){
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            this->setMoved(i, j, false);
        }
    }
}


/* Robots */
/*!
 * \brief Robots' movement behavior
 * \param i0 - current index of ROW
 * \param j0 - current index of COL
 * \param i1 - future index of ROW
 * \param j1 - future index of COL
 */
void Robots::moveRobot(int i0, int j0, int i1, int j1){
    if(i1 < 0 || i1 >= ROWS || j1 < 0 || j1 >= COLS){
        return;
    }
    // Find if robot bumbps into anything while changing position
    switch (this->getItem(i1, j1)){
    case '@':
        this->die();
        break;
    case '+':
        this->setItem(i0, j0, ' ');
        this->killRobot(i1, j1);
        break;
    case '*':
        this->setItem(i0, j0, ' ');
        this->killRobot(i1, j1);
        break;
    case ' ':
        this->setItem(i0, j0, ' ');
        this->setItem(i1, j1, '+');
        this->setMoved(i1, j1, true);
        break;
    }
}

/*!
 * \brief Changing position of each robot
 */
void Robots::moveEachRobot(){
    this->initMovedObjects();

    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            if(this->getItem(i, j) == '+' && this->ifMoved(i, j) == false){
                std::pair<int, int> new_position = this->findCellToMove(i, j);
                this->moveRobot(i, j, new_position.first, new_position.second);
            }
        }
    }
}

/*!
 * \brief Kill robot living in provided cell
 * \param i - current index of ROW
 * \param j - current index of COL
 */
void Robots::killRobot(int i, int j){
    this->setScore(this->getScore() + 10);
    this->setItem(i, j, '*');
}

/*!
 * \brief Find cell that is closest to the player for the robot to move
 * \param i - current index of ROW
 * \param j - current index of COL
 * \return Position - std::pair<int, int>
 */
std::pair<int, int> Robots::findCellToMove(int i, int j){
    std::pair<int, int> current_position = this->getCurrentPosition();
    int di = i - current_position.first;
    int dj = j - current_position.second;

    // generate position which is closest to the player using deltaX(dx) and deltaY(dy)
    if(di > 0 && dj > 0)
        return std::make_pair(i - 1, j - 1);
    else if(di > 0 && dj < 0)
        return std::make_pair(i - 1, j + 1);
    else if(di < 0 && dj > 0)
        return std::make_pair(i + 1, j - 1);
    else if(di < 0 && dj < 0)
        return std::make_pair(i + 1, j - 1);
    else if(di == 0 && dj > 0)
        return std::make_pair(i, j - 1);
    else if(di == 0 && dj < 0)
        return std::make_pair(i, j + 1);
    else if(di > 0 && dj == 0)
        return std::make_pair(i - 1, j);
    else
        return std::make_pair(i + 1, j);
}

/*!
 * \brief Player's move behavior
 * \param i - current index of ROW
 * \param j - current index of COL
 */
void Robots::move(int i, int j){
    if(i < 0 || i >= ROWS || j < 0 || j >= COLS){
        // Player cannot leave the grid
    }else{
        std::pair<int, int> current_position = this->getCurrentPosition();
        this->setItem(current_position.first, current_position.second, ' ');
        // if the cell is empty move there and continue playing, otherwise player dies
        if(this->getItem(i, j) == ' '){
            this->setItem(current_position.first, current_position.second, ' ');
            this->setItem(i, j, '@');
            this->setCurrentPosition(i, j);
        }else{
            this->die();
        }
    }
}

/*!
 * \brief Teleport the player to another cell
 */
void Robots::teleport(){
    std::pair<int, int> new_position = this->findEmptyCell();
    this->move(new_position.first, new_position.second);
}

/*!
 * \brief Kill the player
 */
void Robots::die(){
    this->alive = false;
    std::pair<int, int> current_position = this->getCurrentPosition();
    this->setItem(current_position.first, current_position.second, 'X');
}

/*!
 * \brief Change player's current position
 * \param i - current index of ROW
 * \param j - current index of COL
 */
void Robots::setCurrentPosition(int i, int j){
    this->currentPosition = std::make_pair(i, j);
}

/*!
 * \brief Get player's current position
 * \return Position - std::pair<int, int>
 */
std::pair<int, int> Robots::getCurrentPosition(){
    return this->currentPosition;
}

/*!
 * \brief Reinitialize game
 */
void Robots::redraw(){
    this->score = 0;
    this->level = 0;
    this->alive = true;

    std::srand((unsigned)time( NULL ));
    // Reset gameboard containers
    for(int i = 0; i != ROWS; i++){
        for(int j = 0; j != COLS; j++){
            this->setItem(i, j, ' ');
            this->setMoved(i, j, false);
        }
    }
}

/*!
 * \brief Check if the game is over
 * \return game over
 */
bool Robots::isGameFinished() {
    return checkWinner() != 0;
}
