#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

//    DBTool* dbtool = new DBTool("./TestTableDB");
//    dbtool->verbose = false;
    pgh = new PlayerGameHistory();
    addWindow = new AddPlayerWindow(0, pgh, this);
    selectPlayerWindow = new SelectPlayerWindow(0, pgh, this);
    topPlayersWindow = new TopPlayersWindow(0, pgh, this);
    topGamesWindow = new TopGamesWindow(0, pgh, this);
    statisticsWindow = new StatisticsWindow(0, pgh, this);
    robots = nullptr;
    currentPlayer = nullptr;
}

MainWindow::~MainWindow() {
    delete ui;
    if (pgh != nullptr) delete pgh;
    if (addWindow != nullptr) delete addWindow;
    if (selectPlayerWindow != nullptr) delete selectPlayerWindow;
    if (topPlayersWindow != nullptr) delete topPlayersWindow;
    if (topGamesWindow != nullptr) delete topGamesWindow;
    if (statisticsWindow != nullptr) delete statisticsWindow;
    if (robots != nullptr) delete robots;
}

void MainWindow::on_playRobotsButton_clicked() {
    if(currentPlayer == nullptr){
        // set label to choose player
        this->ui->playerName->setText("Select a player!");
        return;
    }

    if(robots != nullptr) delete robots;
    robots = new RobotsWindow(0, pgh, currentPlayer, this);
    robots->show();
    this->hide();
}

void MainWindow::on_playWormsButton_clicked() {
//    WormsWindow* worms = new WormsWindow();
//    worms->show();
}

void MainWindow::on_exit_triggered() {

}

void MainWindow::on_topPlayers_triggered() {
    topPlayersWindow->refresh();
    topPlayersWindow->show();
    this->hide();
}

void MainWindow::on_topGames_triggered() {
    topGamesWindow->refresh();
    topGamesWindow->show();
    this->hide();
}

void MainWindow::on_newPlayer_triggered() {
    addWindow->clear_fields();
    addWindow->show();
    this->hide();
}

void MainWindow::on_selectPlayer_triggered() {
    selectPlayerWindow->init_list();
    selectPlayerWindow->show();
    this->hide();
}

void MainWindow::on_statistics_triggered() {
    statisticsWindow->refresh();
    statisticsWindow->show();
    this->hide();
}

void MainWindow::showEvent(QShowEvent *event){
    if(currentPlayer != nullptr){
        std::string fullName = "Hello " + currentPlayer->get_first_name() + " "
                + currentPlayer->get_last_name() + " :)";
        this->ui->playerName->setText(QString::fromStdString(fullName));
    }

    event->accept();
}


