#include "robots.h"

Robots::Robots(){
    std::srand((unsigned)time( NULL ));
    std::cout << "Gameboard: " << gameboard << " " << std::endl;
}

Robots::~Robots(){

}

void Robots::setItem(int i, int j, char symbol){
    gameboard[i][j] = symbol;
}

char Robots::getItem(int i, int j){
    return gameboard[i][j];
}

std::string Robots::printGameboard(){
    return "foo";
}

void Robots::moveRobot(){

}

void Robots::killRobot(){

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

    for(int i = 0; i != ROWS; i++){
        for(int j =0; j != COLS; j++){
            this->setItem(i, j, ' ');
        }
    }
}

bool Robots::checkWinner(){
    return true;
}

void Robots::generateRobotPosition(){

}

void Robots::generatePlayerPosition(){

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

