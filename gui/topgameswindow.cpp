#include "topgameswindow.h"
#include "ui_topgameswindow.h"

TopGamesWindow::TopGamesWindow(QWidget *parent, PlayerGameHistory* pgh,
                               MainWindow* menu) : QWidget(parent),
    ui(new Ui::TopGamesWindow) {
    ui->setupUi(this);

    this->pgh = pgh;
    this->menu = menu;

}

TopGamesWindow::~TopGamesWindow() {
    delete ui;
}

void TopGamesWindow::closeEvent(QCloseEvent *event){
    menu->show();
    event->accept();
}

//z/ Move to constructor
void TopGamesWindow::refresh(){
    std::vector<QLabel*> labels{this->ui->player_01,
                this->ui->player_02, this->ui->player_03};
    std::vector<QLabel*> games{this->ui->game_01,
                this->ui->game_02, this->ui->game_03};
    std::vector<QLabel*> scores{this->ui->score_01,
                this->ui->score_02, this->ui->score_03};

    for(int i = 0; i < labels.size(); i++){
        labels[i]->setVisible(false);
        games[i]->setVisible(false);
        scores[i]->setVisible(false);
    }

    int i = 0;
    for(Game* game : top_games()){
        if(i > 2) break;
        labels[i]->setText(QString::fromStdString("# " + game->get_player()->get_first_name() +
                                                  " " + game->get_player()->get_last_name()));
        games[i]->setText(QString::fromStdString(game->get_name()));
        scores[i]->setText(QString::fromStdString(
                               std::to_string(game->get_score())));
        labels[i]->setVisible(true);
        games[i]->setVisible(true);
        scores[i]->setVisible(true);
        i++;
    }
}


/*!
 * \brief Sort the games container
 * \return top vector of sorted games
 */
std::vector<Game*> TopGamesWindow::top_games(){
    std::vector<Game*> top = pgh->get_games();
    struct {
       bool operator()(Game* a, Game* b){
           return a->get_score() > b->get_score();
       }
    } gameComparator;
    std::sort(top.begin(), top.end(), gameComparator);
    return top;
}
