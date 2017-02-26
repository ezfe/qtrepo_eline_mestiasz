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
    return player->get_total_score() / (player->get_games()->get_games().size() + 1);
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
