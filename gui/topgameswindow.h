#ifndef TOPGAMESWINDOW_H
#define TOPGAMESWINDOW_H

#include <QWidget>
#include <QCloseEvent>

#include "../game_history/playergamehistory.h"
#include "mainwindow.h"

class MainWindow;

namespace Ui {
class TopGamesWindow;
}

class TopGamesWindow : public QWidget {
    Q_OBJECT

public:
    explicit TopGamesWindow(QWidget *parent = 0, PlayerGameHistory* pgh = 0,
                            MainWindow* menu = 0);
    ~TopGamesWindow();
    void refresh();

private:
    Ui::TopGamesWindow *ui;

    std::vector<Game*> top_games();

protected:
    MainWindow* menu;
    PlayerGameHistory* pgh;

    void closeEvent(QCloseEvent* event);
};

#endif // TOPGAMESWINDOW_H
