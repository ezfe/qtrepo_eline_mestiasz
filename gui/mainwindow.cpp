#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    pgh = new PlayerGameHistory();
}

MainWindow::~MainWindow() {
    delete ui;
    if(pgh != nullptr) delete pgh;
}

void MainWindow::on_playRobotsButton_clicked() {
    RobotsWindow* robots = new RobotsWindow();
    robots->show();
}

void MainWindow::on_playWormsButton_clicked() {
    WormsWindow* worms = new WormsWindow();
    worms->show();
}

void MainWindow::on_exit_triggered() {

}

void MainWindow::on_topPlayers_triggered()
{

}

void MainWindow::on_topGames_triggered() {


}

void MainWindow::on_newPlayer_triggered() {
    if (addWindow == nullptr) {
        addWindow = new AddPlayerWindow();
        std::cout << "Created window" << std::endl;
    }
    addWindow->show();
}

std::vector<Player*> MainWindow::top_players(){
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
