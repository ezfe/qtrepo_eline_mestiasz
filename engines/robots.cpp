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

char Robots::getItem(int i, int j){
    return gameboard[i][j];
}

bool Robots::ifMoved(int i, int j){
    return this->movedObjects[i][j];
}

std::vector<char> Robots::getOptions(){
    return this->options;
}

std::pair<int, int> Robots::getCurrentPosition(){
    return this->currentPosition;
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
}

void Robots::setMoved(int i, int j, bool b){
    movedObjects[i][j] = b;
}


/* Robots */

void Robots::moveRobot(int i0, int j0, int i1, int j1){
    switch (this->getItem(i1, j1)){
        case '@':
            std::cout << "Kill the player";
            break;
        case '+':
            std::cout << "Kill both robots";
        break;
        case '*':
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

std::vector<int> Robots::findCellToMove(int i, int j){
    return std::vector<int>{1};
}

void Robots::move(int i, int j){

}

void Robots::doNothing(){

}

void Robots::wait(){

}

void Robots::teleport(){

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

int Robots::checkWinner(){
    return 0;
}

std::vector<int> Robots::generateRobotPosition(){
    return std::vector<int>{1, 1};
}

std::vector<int> Robots::generatePlayerPosition(){
    return std::vector<int>{1, 1};
}

void Robots::checkOptions(){

}

void Robots::showRanking(){

}

void Robots::jump(){

}

void Robots::playAutoMode(){

}
