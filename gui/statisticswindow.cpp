#include "statisticswindow.h"
#include "ui_statisticswindow.h"

StatisticsWindow::StatisticsWindow(QWidget *parent, PlayerGameHistory* pgh,
                                   MainWindow* menu) : QWidget(parent),
    ui(new Ui::StatisticsWindow) {
    ui->setupUi(this);

    this->pgh = pgh;
    this->menu = menu;
}

StatisticsWindow::~StatisticsWindow() {
    delete ui;
}

/*!
 * \brief Override close event
 */
void StatisticsWindow::closeEvent(QCloseEvent *event){
    menu->show();
    event->accept();
}

/*!
 * \brief Refresh the statistics and display
 */
void StatisticsWindow::refresh(){
    ui->label_01->setText(QString::fromStdString(
                             std::to_string(pgh->number_games_played())));
    ui->label_02->setText(QString::fromStdString(
                              std::to_string(pgh->number_players_played())));
    ui->label_03->setText(QString::fromStdString(
                              std::to_string(pgh->top_game_score())));
    ui->label_04->setText(QString::fromStdString(
                              std::to_string(pgh->avg_games_per_player())));
    ui->label_05->setText(QString::fromStdString(
                              std::to_string(pgh->avg_game_score())));
}
