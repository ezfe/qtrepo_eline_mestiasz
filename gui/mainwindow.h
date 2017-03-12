#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QShowEvent>

#include "../game_history/playergamehistory.h"
#include "addplayerwindow.h"
#include "selectplayerwindow.h"
#include "topplayerswindow.h"
#include "topgameswindow.h"
#include "statisticswindow.h"
#include "robotswindow.h"
#include "wormswindow.h"
#include "../game_history/dbtool.h"

class AddPlayerWindow;
class SelectPlayerWindow;
class TopPlayersWindow;
class TopGamesWindow;
class StatisticsWindow;
class RobotsWindow;
class WormsWindow;

namespace Ui {
    class MainWindow;
}

class MainWindow: public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    Player* currentPlayer;

private slots:
    void on_playRobotsButton_clicked();
    void on_playWormsButton_clicked();

    void on_exit_triggered();
    void on_topPlayers_triggered();
    void on_topGames_triggered();
    void on_newPlayer_triggered();
    void on_selectPlayer_triggered();
    void on_statistics_triggered();

private:
    Ui::MainWindow* ui;
    PlayerGameHistory* pgh;
    AddPlayerWindow* addWindow;
    SelectPlayerWindow* selectPlayerWindow;
    TopPlayersWindow* topPlayersWindow;
    TopGamesWindow* topGamesWindow;
    StatisticsWindow* statisticsWindow;
    RobotsWindow* robots;
    WormsWindow* worms;

protected:
    void showEvent(QShowEvent* event);
};

#endif // MAINWINDOW_H
