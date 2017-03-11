#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QShowEvent>

#include "../game_history/playergamehistory.h"
#include "addplayerwindow.h"
#include "selectplayerwindow.h"
#include "topplayerswindow.h"
#include "robotswindow.h"

class AddPlayerWindow;
class SelectPlayerWindow;
class TopPlayersWindow;
class RobotsWindow;

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

private:
    Ui::MainWindow* ui;
    PlayerGameHistory* pgh;
    AddPlayerWindow* addWindow;
    SelectPlayerWindow* selectPlayerWindow;
    TopPlayersWindow* topPlayersWindow;
    RobotsWindow* robots;
    //WormsWindow* wormsWindow;

private slots:
    void on_exit_triggered();
    void on_topPlayers_triggered();
    void on_topGames_triggered();
    void on_newPlayer_triggered();
    void on_selectPlayer_triggered();

protected:
    void showEvent(QShowEvent* event);
};

#endif // MAINWINDOW_H
