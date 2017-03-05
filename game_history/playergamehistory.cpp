#include "playergamehistory.h"

PlayerGameHistory::PlayerGameHistory() {
    this->players.clear();
    this->games.clear();
}

PlayerGameHistory::PlayerGameHistory(DBTool* dbtool) {
    this->players.clear();
    this->games.clear();

    if (dbtool == nullptr) {
        /* Just won't load anything */
        return;
    }

    this->db = dbtool;

    DBTablePlayers* playerTable = new DBTablePlayers(dbtool, PLAYER_TABLE_NAME);
    DBTableGames* gameTable = new DBTableGames(dbtool, GAME_TABLE_NAME);

    int playerCode = SQLITE_ERROR;
    sqlite3_stmt* playerSelectStatement = nullptr;
    playerCode = sqlite3_prepare_v2(dbtool->db(), playerTable->select_all_sql().c_str(), -1, &playerSelectStatement, nullptr);

    /* Loop through results */
    if (playerCode == SQLITE_OK && playerSelectStatement != nullptr) {
        while (sqlite3_step(playerSelectStatement) == SQLITE_ROW) {
            /* Create Player p */
            const char* firstTemp = reinterpret_cast<const char*>(sqlite3_column_text(playerSelectStatement, 1));
            std::string firstName = firstTemp == NULL ? "null" : std::string(firstTemp);

            const char* lastTemp = reinterpret_cast<const char*>(sqlite3_column_text(playerSelectStatement, 2));
            std::string lastName = lastTemp == NULL ? "null" : std::string(lastTemp);

            const char* addressTemp = reinterpret_cast<const char*>(sqlite3_column_text(playerSelectStatement, 3));
            std::string address = addressTemp == NULL ? "null" : std::string(addressTemp);

            Player* p = new Player(firstName, lastName, address);
            p->set_table_id(sqlite3_column_int(playerSelectStatement, 0));

            /* Fetch games */
            int gameCode = SQLITE_ERROR;
            sqlite3_stmt* gameSelectStatement = nullptr;
            std::string gameQueryText("SELECT * FROM GameList WHERE player = " + std::to_string(p->get_table_id()) + ";");
            gameCode = sqlite3_prepare_v2(dbtool->db(), gameQueryText.c_str(), -1, &gameSelectStatement, nullptr);

            /* Loop through results */
            if (gameCode == SQLITE_OK && gameSelectStatement != nullptr) {
                while (sqlite3_step(gameSelectStatement) == SQLITE_ROW) {
                    const char* nameTemp = reinterpret_cast<const char*>(sqlite3_column_text(gameSelectStatement, 2));
                    std::string name = nameTemp == NULL ? "null" : std::string(nameTemp);

                    Game* g = new Game(p, name, sqlite3_column_int(gameSelectStatement, 1));

                    this->add_game(p, g);
                }
            }

            sqlite3_finalize(gameSelectStatement);
        }
    } else {
        std::cerr << "SQL Error: " << sqlite3_errmsg(dbtool->db()) << std::endl;
    }

    sqlite3_finalize(playerSelectStatement);

    delete playerTable;
    delete gameTable;
    dbtool->close();
}

PlayerGameHistory::~PlayerGameHistory() {
    if (this->db != nullptr) {
        if (!db->isOpen()) db->open();

        DBTablePlayers* playerTable = new DBTablePlayers(this->db, PLAYER_TABLE_NAME);
        DBTableGames* gameTable = new DBTableGames(this->db, GAME_TABLE_NAME);

        int playerid = 0;

        playerTable->drop();
        playerTable->create();
        for (Player* player: this->players) {
            player->set_table_id(playerid++);
            playerTable->add_row(player->get_table_id(), player->get_first_name(), player->get_last_name(), player->get_address());
        }

        int gameid = 0;

        gameTable->drop();
        gameTable->create();
        for (Game* game: this->games) {
            game->set_table_id(gameid);
            gameTable->add_row(game->get_table_id(), game->get_score(), game->get_name(), game->get_player()->get_table_id());

            gameid++;
        }

        delete playerTable;
        delete gameTable;
        delete this->db;
    }
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
    if(players.size() != 0)
        return 1.0 * games.size() / players.size();
    return 0;
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
    return 1.0 * player->get_total_score() / (player->get_game_history()->get_games().size() + 1);
}

/*!
 * \brief Query the average game score across all games
 * \return double average score
 */
double PlayerGameHistory::avg_game_score() {
    double sum = 0;
    for(auto game : games){
        sum += game->get_score();
    }
    if(games.size() != 0)
        return sum / games.size();
    return 0;
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
    for(Player* player : players){
        if (player == p || (player->get_table_id() >= 0 && player->get_table_id() == p->get_table_id())){
            exists = true;
            break;
        }
    }

    if(!exists) {
        players.push_back(p);
    }
    p->add_game(g);
}

/*!
 * \brief Add a
 * \param f the name of the player
 * \param l the lastname of the player
 * \param a player's address
 */
void PlayerGameHistory::add_player(std::string f, std::string l, std::string a) {
    for(Player* player : players){
        if(player->get_first_name() == f && player->get_last_name() == l &&
                player->get_address() == a) return;
    }
    Player* player = new Player(f, l, a);
    this->players.push_back(player);
}

/*!
 * \brief Simple Unique ID Finder
 * \return valid table ID
 */
int PlayerGameHistory::get_valid_table_id() {
    int id = 0;
    for(Player* player: players) {
        if (player->get_table_id() > id) {
            id = player->get_table_id() + 1;
        }
    }
    return id;
}
