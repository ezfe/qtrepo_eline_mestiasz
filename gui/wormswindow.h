#ifndef WORMSWINDOW_H
#define WORMSWINDOW_H

#include <QWidget>
#include <QCloseEvent>
#include "../engines/engine.h"
#include "../engines/worms.h"
#include "../game_history/playergamehistory.h"
#include "mainwindow.h"

class MainWindow;

namespace Ui {
class WormsWindow;
}

class WormsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit WormsWindow(QWidget *parent = 0, PlayerGameHistory* pgh = 0,
                         Player* player = 0, MainWindow* menu = 0);
    ~WormsWindow();

    void handle_event(char cmd);
    void save_game();

private slots:
    void on_resetGame_clicked();

    void on_upButton_clicked();

    void on_downButton_clicked();

    void on_rightButton_clicked();

    void on_leftButton_clicked();

private:
    Ui::WormsWindow *ui;
    Engine * engine;
    void refresh_gameboard();

protected:
    MainWindow* menu;
    PlayerGameHistory* pgh;
    Player* player;
    std::string name;

    void closeEvent(QCloseEvent* event);
};

#endif // WORMSWINDOW_H
