#include "robots.h"

Robots::Robots(){
    std::cout << "Gameboard: " << gameboard << " " << std::endl;
    this->redraw();
    this->addPlayerAndRobots();
}

Robots::~Robots(){

}

/* Controller */
void Robots::setupController(){
    char cmd;
    std::cout << "Insert a command" << std::endl;

    std::pair<int, int> current_position;
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
        if(this->checkWinner() != 0){
            std::cout << "Score: " << this->getScore() << std::endl << std::endl << std::endl;
            this->redraw();
            this->addPlayerAndRobots();
            std::cout << this->printGameboard();
        }
        std::cout << "Insert a command" << std::endl;
    }
}

/* Gameboard */

int Robots::getScore(){
    return this->score;
}

int Robots::getLevel(){
    return this->level;
}

bool Robots::isAlive(){
    return this->alive;
}

char Robots::getItem(int i, int j){
    return gameboard[i][j];
}

bool Robots::ifMoved(int i, int j){
    return this->movedObjects[i][j];
}

int Robots::checkWinner(){
    int counter_of_robots = 0;
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            if(this->getItem(i, j) == '+')
                counter_of_robots++;
        }
    }

    if(isAlive() && counter_of_robots != 0) return 0;
    if(isAlive() && counter_of_robots == 0) return 1;

    return 2;
}

std::vector<char> Robots::getOptions(){
    return this->options;
}

std::string Robots::printGameboard(){
    std::stringstream ss;
    for(int i = 0; i < ROWS; i++){
        ss << "#" << i << ":   ";
        for(int j = 0; j < COLS; j++){
            ss << this->getItem(i, j);
        }
        ss << std::endl;
    }

    return ss.str();
}

std::pair<int, int> Robots::findEmptyCell(){
    std::vector<std::pair<int, int>> empty_cells;
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            if(this->getItem(i, j) == ' '){
                empty_cells.push_back(std::make_pair(i, j));
            }
        }
    }

    if(empty_cells.size() != 0){
        int index = rand() % empty_cells.size();
        return empty_cells.at(index);
    }

    return std::make_pair(-1, -1);
}

void Robots::setItem(int i, int j, char symbol){
    gameboard[i][j] = symbol;
    if(symbol == '@') this->setCurrentPosition(i, j);
}

void Robots::setMoved(int i, int j, bool b){
    movedObjects[i][j] = b;
}

void Robots::setScore(int score){
    this->score = score;
}

void Robots::addPlayerAndRobots(){
    std::pair<int, int> empty_cell;
    for(int i = 0; i < ROBOTS; i++){
        empty_cell = findEmptyCell();
        this->setItem(empty_cell.first, empty_cell.second, '+');
    }

    empty_cell = findEmptyCell();
    this->setItem(empty_cell.first, empty_cell.second, '@');

}

void Robots::initMovedObjects(){
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            this->setMoved(i, j, false);
        }
    }
}


/* Robots */

void Robots::moveRobot(int i0, int j0, int i1, int j1){
    if(i1 < 0 || i1 >= ROWS || j1 < 0 || j1 >= COLS){
        return;
    }

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
    default:
        std::cout << "Robot changed position" << std::endl;
    }
}

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

void Robots::killRobot(int i, int j){
    this->setScore(this->getScore() + 10);
    this->setItem(i, j, '*');
}

std::pair<int, int> Robots::findCellToMove(int i, int j){
    std::pair<int, int> current_position = this->getCurrentPosition();
    int di = i - current_position.first;
    int dj = j - current_position.second;

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

void Robots::move(int i, int j){
    if(i < 0 || i >= ROWS || j < 0 || j >= COLS){
        std::cout << "Player cannot leave the grid " << std::endl;
    }else{
        std::pair<int, int> current_position = this->getCurrentPosition();
        this->setItem(current_position.first, current_position.second, ' ');
        if(this->getItem(i, j) == ' '){
            this->setItem(current_position.first, current_position.second, ' ');
            this->setItem(i, j, '@');
            this->setCurrentPosition(i, j);
        }else{
            this->die();
        }
    }
}

void Robots::doNothing(){

}

void Robots::wait(){

}

void Robots::teleport(){
    std::pair<int, int> new_position = this->findEmptyCell();
    this->move(new_position.first, new_position.second);
}

void Robots::die(){
    this->alive = false;
    std::pair<int, int> current_position = this->getCurrentPosition();
    this->setItem(current_position.first, current_position.second, 'X');
}

void Robots::setCurrentPosition(int i, int j){
    this->currentPosition = std::make_pair(i, j);
}

std::pair<int, int> Robots::getCurrentPosition(){
    return this->currentPosition;
}

void Robots::redraw(){
    this->score = 0;
    this->level = 0;
    this->alive = true;

    std::srand((unsigned)time( NULL ));

    for(int i = 0; i != ROWS; i++){
        for(int j =0; j != COLS; j++){
            this->setItem(i, j, ' ');
            this->setMoved(i, j, false);
        }
    }
}

void Robots::checkOptions(){

}

void Robots::showRanking(){

}

void Robots::jump(){

}

void Robots::playAutoMode(){

}
