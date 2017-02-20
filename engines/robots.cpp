#include "robots.h"

Robots::Robots(int rows, int cols, int robots): Engine(rows, cols) {

    movedObjects = new bool*[rows];
    for(int i = 0; i < rows; i++) {
        movedObjects[i] = new bool[cols];
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            movedObjects[i][j] = false;
        }
    }

    this->redraw();
    this->add_player_and_robots();
    this->ROBOTS = robots;
}

Robots::~Robots(){
    delete this->movedObjects;
    std::cout << "Robots destructed" << std::endl;
}

/* Controller */

std::string Robots::controller(char cmd){
    std::pair<int, int> current_position = this->get_current_position();
    std::stringstream board;

    // Disable commands once the player loses or wins the game
    // stays disabled until he/she presses 'r' or 'q' to get to
    // main menu
    if (this->check_winner() != 0 && cmd != 'r'){
        // don't execute commands
    }else{

        switch(cmd){
        case 'w':
            while(this->check_winner() == 0){
                this->move_each_robot();
            }
            break;
        case 't':
            this->teleport();
            break;
        case 'r':
            this->redraw();
            this->add_player_and_robots();
            break;
        case 'y':
            this->move(current_position.first - 1, current_position.second - 1);
            if (this->moved) this->move_each_robot();
            break;
        case 'k':
            this->move(current_position.first - 1, current_position.second);
            if (this->moved) this->move_each_robot();
            break;
        case 'u':
            this->move(current_position.first - 1, current_position.second + 1);
            if (this->moved) this->move_each_robot();
            break;
        case 'h':
            this->move(current_position.first, current_position.second - 1);
            if (this->moved) this->move_each_robot();
            break;
        case 'l':
            this->move(current_position.first, current_position.second + 1);
            if (this->moved) this->move_each_robot();
            break;
        case 'b':
            this->move(current_position.first + 1, current_position.second - 1);
            if (this->moved) this->move_each_robot();
            break;
        case 'j':
            this->move(current_position.first + 1, current_position.second);
            if (this->moved) this->move_each_robot();
            break;
        case 'n':
            this->move(current_position.first + 1, current_position.second + 1);
            if (this->moved) this->move_each_robot();
            break;
        }
    }

    // Display score and the gameboard

    board << this->print_gameboard()
          << "Score: " << this->get_score()
          << std::endl << std::endl << std::endl;
    return board.str();

}

/* Gameboard */
/*!
 * \brief Get the score
 * \return Current score - int
 */
int Robots::get_score(){
    return this->score;
}

/*!
 * \brief Get the level
 * \return current level - int
 */
int Robots::get_level(){
    return this->level;
}

/*!
 * \brief Find if player is alive
 * \return Alive - bool
 */
bool Robots::is_alive(){
    return this->alive;
}

/*!
 * \brief Find if player can move to that cell
 * \return bool
 */

bool Robots::check_cell(int i, int j){
    std::pair<int, int> current_position = this->get_current_position();
    this->set_current_position(i, j);

    // Check if any robot can move to that cell in this unit of time
    for(int k = 0; k < ROWS; k++){
        for(int z = 0; z < COLS; z++){
           if(this->get_item(k, z) == '+'){
               std::pair<int, int> cell = this->find_cell_to_move(k, z);
               if(cell.first == i && cell.second == j){
                   this->set_current_position(current_position.first,
                                              current_position.second);
                   return false;
               }
           }
        }
    }

    // restore the location of the robot
    this->set_current_position(current_position.first,
                               current_position.second);
    return true;
}

/*!
 * \brief Get the cell valeu from gameboard
 * \param i - index of ROW
 * \param j - index of COL
 * \return The symbolt from gameboard - char
 */
char Robots::get_item(int i, int j){
    return get(i, j);
}

/*!
 * \brief Find if robot has moved already
 * \param i - index of ROW
 * \param j - index of COL
 * \return Moved - bool
 */
bool Robots::if_moved(int i, int j){
    return this->movedObjects[i][j];
}

/*!
 * \brief Find if someone won already
 * \return winner - 0 - not yet, 1 - player, 2 - robots won
 */
int Robots::check_winner(){
    int counter_of_robots = 0;
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            if(this->get_item(i, j) == '+')
                counter_of_robots++;
        }
    }

    // If player is alive and there are robots game continues
    if(is_alive() && counter_of_robots != 0) return 0;
    // If player is alive and there are no robots player wins
    if(is_alive() && counter_of_robots == 0) return 1;

    return 2;
}

/*!
 * \brief Find empty cell where player or robot can be
 * positioned in the begining of the game
 * \return Position - std::pair<int, int>
 */
std::pair<int, int> Robots::find_empty_cell(){
    std::vector<std::pair<int, int>> empty_cells;
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            if(this->get_item(i, j) == ' '){
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
void Robots::set_item(int i, int j, char symbol){
    set(i, j, symbol);
    if(symbol == '@') this->set_current_position(i, j);
}

/*!
 * \brief Change bool value of the cell
 * \param i - index of ROW
 * \param j - index of COL
 * \param b - value that we want to set
 */
void Robots::set_moved(int i, int j, bool b){
    movedObjects[i][j] = b;
}

/*!
 * \brief Change value of the cell
 * \param score - new score
 */
void Robots::set_score(int score){
    this->score = score;
}

/*!
 * \brief Add players and robots to the gameboard
 */
void Robots::add_player_and_robots(){
    std::pair<int, int> empty_cell;
    for(int i = 0; i < ROWS; i++){
        empty_cell = find_empty_cell();
        this->set_item(empty_cell.first, empty_cell.second, '+');
    }

    // Finally add the player to the gameboard
    empty_cell = find_empty_cell();
    this->set_item(empty_cell.first, empty_cell.second, '@');
}

/*!
 * \brief Set bool value of every cell to false, so
 * the robots can move again
 */
void Robots::init_moved_objects(){
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            this->set_moved(i, j, false);
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
void Robots::move_robot(int i0, int j0, int i1, int j1){
    if(i1 < 0 || i1 >= ROWS || j1 < 0 || j1 >= COLS){
        return;
    }
    // Find if robot bumbps into anything while changing position
    switch (this->get_item(i1, j1)){
    case '@':
        this->die();
        break;
    case '+':
        this->set_item(i0, j0, ' ');
        this->kill_robot(i1, j1);
        break;
    case '*':
        this->set_item(i0, j0, ' ');
        this->kill_robot(i1, j1);
        break;
    case ' ':
        this->set_item(i0, j0, ' ');
        this->set_item(i1, j1, '+');
        this->set_moved(i1, j1, true);
        break;
    }
}

/*!
 * \brief Changing position of each robot
 */
void Robots::move_each_robot(){
    this->init_moved_objects();

    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            if(this->get_item(i, j) == '+' && this->if_moved(i, j) == false){
                std::pair<int, int> new_position = this->find_cell_to_move(i, j);
                this->move_robot(i, j, new_position.first, new_position.second);
            }
        }
    }
}

/*!
 * \brief Kill robot living in provided cell
 * \param i - current index of ROW
 * \param j - current index of COL
 */
void Robots::kill_robot(int i, int j){
    this->set_score(this->get_score() + 10);
    this->set_item(i, j, '*');
}

/*!
 * \brief Find cell that is closest to the player for the robot to move
 * \param i - current index of ROW
 * \param j - current index of COL
 * \return Position - std::pair<int, int>
 */
std::pair<int, int> Robots::find_cell_to_move(int i, int j){
    std::pair<int, int> current_position = this->get_current_position();
    int di = i - current_position.first;
    int dj = j - current_position.second;

    // generate position which is closest to the player
    // using deltaX(dx) and deltaY(dy)
    if(di > 0 && dj > 0)
        return std::make_pair(i - 1, j - 1);
    else if(di > 0 && dj < 0)
        return std::make_pair(i - 1, j + 1);
    else if(di < 0 && dj > 0)
        return std::make_pair(i + 1, j - 1);
    else if(di < 0 && dj < 0)
        return std::make_pair(i + 1, j + 1);
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
        this->moved = false;
    }else{
        std::pair<int, int> current_position = this->get_current_position();

        // if the cell is empty move there and continue playing,
        // otherwise player dies
        if(this->get_item(i, j) == ' ' && this->check_cell(i, j)){
            this->set_item(current_position.first,
                           current_position.second, ' ');
            this->set_item(i, j, '@');
            this->set_current_position(i, j);
            this->moved = true;
        }else{
            this->moved = false;
        }
    }
}

/*!
 * \brief Teleport the player to another cell
 */
void Robots::teleport(){
    int i = rand() % ROWS;
    int j = rand() % COLS;
    std::pair<int, int> current_position = this->get_current_position();

    this->set_item(current_position.first, current_position.second, ' ');
    if (this->get_item(i, j) == '+' || this->get_item(i, j) == '*'){
        die();
    } else {
        this->set_item(i, j, '@');
        this->set_current_position(i, j);
    }

}

/*!
 * \brief Kill the player
 */
void Robots::die(){
    this->alive = false;
    std::pair<int, int> current_position = this->get_current_position();
    this->set_item(current_position.first, current_position.second, 'X');
}

/*!
 * \brief Change player's current position
 * \param i - current index of ROW
 * \param j - current index of COL
 */
void Robots::set_current_position(int i, int j){
    this->currentPosition = std::make_pair(i, j);
}

/*!
 * \brief Get player's current position
 * \return Position - std::pair<int, int>
 */
std::pair<int, int> Robots::get_current_position(){
    return this->currentPosition;
}

/*!
 * \brief Reinitialize game
 */
void Robots::redraw(){
    this->score = 0;
    this->level = 0;
    this->alive = true;
    this->moved = false;

    std::srand((unsigned)time( NULL ));
    // Reset gameboard containers
    for(int i = 0; i != ROWS; i++){
        for(int j = 0; j != COLS; j++){
            this->set_item(i, j, ' ');
            this->set_moved(i, j, false);
        }
    }
}

/*!
 * \brief Check if the game is over
 * \return game over
 */
bool Robots::is_game_finished() {
    return check_winner() != 0;
}

/*!
 * \brief Reset this game
 */
void Robots::reset_game() {
    this->redraw();
}
