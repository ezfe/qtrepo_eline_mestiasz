#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    DBTool* dbtool = new DBTool("/Users/prosperi/Development/CS205/qtrepo_eline_mestiasz/gui/TestTableDB");
    dbtool->verbose = false;
    pgh = new PlayerGameHistory(dbtool);
    addWindow = new AddPlayerWindow(0, pgh, this);
    selectPlayerWindow = new SelectPlayerWindow(0, pgh, this);
    topPlayersWindow = new TopPlayersWindow(0, pgh, this);
    topGamesWindow = new TopGamesWindow(0, pgh, this);
    statisticsWindow = new StatisticsWindow(0, pgh, this);
    robots = nullptr;
    worms = nullptr;
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
    if (worms != nullptr) delete robots;
}

/*!
 * \brief Open Robots Window
 */
void MainWindow::on_playRobotsButton_clicked() {
    if(currentPlayer == nullptr){
        // The user should choose a player
        this->ui->playerName->setText("Select a player!");
        return;
    }
    // delete previous robots window container
    if(robots != nullptr) delete robots;
    robots = new RobotsWindow(0, pgh, currentPlayer, this);
    robots->show();
    this->hide();
}

/*!
 * \brief Open Worms Window
 * \param MainWindow* menu
 */
void MainWindow::on_playWormsButton_clicked() {
    if(currentPlayer == nullptr){
        // The user should choose a player
        this->ui->playerName->setText("Select a player!");
        return;
    }
    // delete previous worms window container
    if(worms != nullptr) delete worms;
    worms = new WormsWindow(0, pgh, currentPlayer, this);
    worms->show();
    this->hide();
}

/*!
 * \brief Close the application
 */
void MainWindow::on_exit_triggered() {
    this->close();
}

/*!
 * \brief Open top players window
 */
void MainWindow::on_topPlayers_triggered() {
    topPlayersWindow->refresh();
    topPlayersWindow->show();
    this->hide();
}

/*!
 * \brief Open top games window
 */
void MainWindow::on_topGames_triggered() {
    topGamesWindow->refresh();
    topGamesWindow->show();
    this->hide();
}

/*!
 * \brief Open new players window
 */
void MainWindow::on_newPlayer_triggered() {
    addWindow->clear_fields();
    addWindow->show();
    this->hide();
}

/*!
 * \brief Open select players window
 */
void MainWindow::on_selectPlayer_triggered() {
    selectPlayerWindow->init_list();
    selectPlayerWindow->show();
    this->hide();
}

/*!
 * \brief Open statistics window
 */
void MainWindow::on_statistics_triggered() {
    statisticsWindow->refresh();
    statisticsWindow->show();
    this->hide();
}

/*!
 * \brief Override show event
 * \param QShowEvent* event
 */
void MainWindow::showEvent(QShowEvent* event){
    if(currentPlayer != nullptr){
        std::string fullName = "Hello " + currentPlayer->get_first_name() + " "
                + currentPlayer->get_last_name() + " :)";
        this->ui->playerName->setText(QString::fromStdString(fullName));
    }

    event->accept();
}


