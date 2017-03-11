#include "topplayerswindow.h"
#include "ui_topplayerswindow.h"

TopPlayersWindow::TopPlayersWindow(QWidget *parent,  PlayerGameHistory* pgh,
                                   MainWindow* menu) : QWidget(parent),
    ui(new Ui::TopPlayersWindow){
    ui->setupUi(this);
    this->pgh = pgh;
    this->menu = menu;
}

TopPlayersWindow::~TopPlayersWindow()
{
    delete ui;
}

void TopPlayersWindow::closeEvent(QCloseEvent *event){
    menu->show();
    event->accept();
}

void TopPlayersWindow::refresh(){
    std::vector<QLabel*> labels{this->ui->player_01,
                this->ui->player_02, this->ui->player_03};
    std::vector<QLabel*> scores{this->ui->score_01,
                this->ui->score_02, this->ui->score_03};

    for(int i = 0; i < labels.size(); i++){
        labels[i]->setVisible(false);
        scores[i]->setVisible(false);
    }

    int i = 0;
    for(Player* player : top_players()){
        if(i > 2) break;
        labels[i]->setText(QString::fromStdString("# " + player->get_first_name() +
                                                  " " + player->get_last_name()));
        scores[i]->setText(QString::fromStdString(
                               std::to_string(pgh->avg_score_per_player(player))));
        labels[i]->setVisible(true);
        scores[i]->setVisible(true);
        i++;
    }
}

std::vector<Player*> TopPlayersWindow::top_players(){
    std::vector<Player*> top = pgh->get_players();
    struct {
       bool operator()(Player* a, Player* b){
           int tmpA = a->get_game_history()->get_games().size();
           if(tmpA == 0) return 0;
           int tmpB = b->get_game_history()->get_games().size();
           if(tmpB == 0) return 1;
           return (a->get_total_score()/tmpA) >
                  (b->get_total_score()/tmpB);
       }
    } playerComparator;
    std::sort(top.begin(), top.end(), playerComparator);
    return top;
}
