#include "robots.h"

Robots::Robots(){
    std::cout << "Gameboard: " << gameboard << " " << std::endl;
}

Robots::~Robots(){

}

void Robots::setItem(int i, int j, char symbol){
    gameboard[i][j] = symbol;
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

std::string Robots::printGameboard(){
    return "foo";
}

std::vector<int> Robots::findEmptyCell(){
    return std::vector<int>{1};
}

void Robots::moveRobot(int i0, int j0, int i1, int j1){

}

void Robots::killRobot(int i, int j){

}

std::vector<int> Robots::findCellToMove(int i, int j){
    return std::vector<int>{1};
}

void Robots::move(){

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

bool Robots::checkWinner(){
    return true;
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

std::vector<char> Robots::getOptions(){
    return this->options;
}

int Robots::getScore(){
    return this->score;
}

int Robots::getLevel(){
    return this->level;
}

bool Robots::isAlive(){
    return this->alive;
}
