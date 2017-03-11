#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../gui_robots/robotswindow.h"
#include "../gui_worms/wormswindow.h"
#include "../game_history/playergamehistory.h"
#include "addplayerwindow.h"

class AddPlayerWindow;

namespace Ui {
    class MainWindow;
}

class MainWindow: public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    std::vector<Player*> top_players();

private slots:
    void on_playRobotsButton_clicked();

    void on_playWormsButton_clicked();

private:
    Ui::MainWindow *ui;
    PlayerGameHistory* pgh;
    AddPlayerWindow* addWindow = nullptr;

private slots:
    void on_exit_triggered();
    void on_topPlayers_triggered();
    void on_topGames_triggered();
    void on_newPlayer_triggered();
};

#endif // MAINWINDOW_H
