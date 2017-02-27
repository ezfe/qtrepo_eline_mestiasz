#include "playergamehistory.h"

PlayerGameHistory::PlayerGameHistory() {
    this->players.clear();
    this->games.clear();
}

PlayerGameHistory::~PlayerGameHistory() {
    for(auto player : this->players){
        delete player;
    }
}

/*!
 * \brief Query total number of games played across all players
 * \return int total games played
 */
int PlayerGameHistory::number_games_played() {
    return games.size();
}

/*!
 * \brief Query total number of players who have played games
 * \return int total number of players
 */
int PlayerGameHistory::number_players_played() {
    return players.size();
}

/*!
 * \brief Query average number of games per player
 * \return double average games per player
 */
double PlayerGameHistory::avg_games_per_player() {
    return games.size() / players.size();
}

/*!
 * \brief Query the top game score
 * \return int the top game score
 */
int PlayerGameHistory::top_game_score() {
    int max = 0;
    for(auto game : games){
        if(max < game->get_score())
            max = game->get_score();
    }
    return max;
}

/*!
 * \brief Query the average score for a specific player
 * \param player to check
 * \return double average score
 */
double PlayerGameHistory::avg_score_per_player(Player* player) {
    return player->get_total_score() / (player->get_game_history()->get_games().size() + 1);
}

/*!
 * \brief Query the average game score across all games
 * \return double average score
 */
double PlayerGameHistory::avg_game_score() {
   int sum = 0;
   for(auto game : games){
        sum += game->get_score();
   }
   return sum / games.size();
}

/*!
 * \brief Get all the players
 * \return std::vector<Player*> players
 */
std::vector<Player*> PlayerGameHistory::get_players(){
    return this->players;
}

/*!
 * \brief Get all the games
 * \return std::vector<Game*> games
 */
std::vector<Game*> PlayerGameHistory::get_games(){
    return this->games;
}

/*!
 * \brief Add a game
 * \param p the player who played
 * \param g the game they played
 */
void PlayerGameHistory::add_game(Player* p, Game* g) {
    games.push_back(g);
    bool exists = false;
    for(auto player : players){
        if(player == p){
            exists = true;
            break;
        }
    }

    if(!exists) players.push_back(p);
    p->add_game(g);
}
