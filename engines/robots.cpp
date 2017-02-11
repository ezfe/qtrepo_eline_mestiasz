#include "robots.h"

Robots::Robots(){
    std::cout << "Gameboard: " << gameboard << " " << std::endl;
    this->redraw();
}

Robots::~Robots(){

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

void Robots::setMoved(int i, int j, bool b){
    movedObjects[i][j] = b;
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
            ss << j << "/" << this->getItem(i, j) << " | ";
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


/* Robots */

void Robots::moveRobot(int i0, int j0, int i1, int j1){
    if(i1 < 0 || i1 >= ROWS || j1 < 0 || j1 >= COLS){
        std::cout << "Robot cannot leave the grid" << std::endl;
        return;
    }

    switch (this->getItem(i1, j1)){
        case '@':
            std::cout << "Kill the player";
            this->die();
            break;
        case '+':
            this->setItem(i0, j0, ' ');
            this->killRobot(i1, j1);
            std::cout << "Kill both robots";
            break;
        case '*':
            this->setItem(i0, j0, ' ');
            this->killRobot(i1, j1);
            std::cout << "Kill the robot that moved to that cell";
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

void Robots::killRobot(int i, int j){
    this->setItem(i, j, '*');
}

std::pair<int, int> Robots::findCellToMove(int i, int j){
    return std::make_pair(1, 1);
}

void Robots::move(int i, int j){
    if(i < 0 || i >= ROWS || j < 0 || j >= COLS){
        std::cout << "Player cannot leave the grid" << std::endl;
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
    std::cout << "Player just passed away" << std::endl;
}

void Robots::setCurrentPosition(int i, int j){
    this->currentPosition = std::make_pair(i, j);
}

std::pair<int, int> Robots::getCurrentPosition(){
    return this->currentPosition;
}

void Robots::quit(){

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
