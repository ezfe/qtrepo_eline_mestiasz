#include "playergamehistory.h"

PlayerGameHistory::PlayerGameHistory() {

}

PlayerGameHistory::~PlayerGameHistory() {

}

int PlayerGameHistory::number_games_played() {
    return games.size();
}

int PlayerGameHistory::number_players_played() {
    return players.size();
}

double PlayerGameHistory::avg_games_per_player() {
    return games.size() / players.size();
}

int PlayerGameHistory::top_game_score() {
    int max = 0;
    for(auto game : games){
        if(max < game->get_score())
            max = game->get_score();
    }
    return max;
}

double PlayerGameHistory::avg_score_per_player(Player* player) {
    int score_counter = 0;
    int game_counter = 0;
    for(auto game : games){
        if(game->get_player() == player){
            game_counter++;
            score_counter += game->get_score();
        }
    }
    return score_counter / game_counter;
}

double PlayerGameHistory::avg_game_score() {
   int sum = 0;
   for(auto game : games){
        sum += game->get_score();
   }
   return sum / games.size();
}

std::vector<Player*> PlayerGameHistory::get_players(){
    return this->players;
}

std::vector<Game*> PlayerGameHistory::get_games(){
    return this->games;
}

void PlayerGameHistory::add_game(Player* p, Game* g) {
    games.push_back(g);
    bool t = true;
    for(auto player : players){
        if(player == p){
            t = false;
            break;
        }
    }

    if(t) players.push_back(p);

}
