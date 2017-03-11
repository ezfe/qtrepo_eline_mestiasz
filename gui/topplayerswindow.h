#ifndef TOPPLAYERSWINDOW_H
#define TOPPLAYERSWINDOW_H

#include <QWidget>
#include <QCloseEvent>

#include "../game_history/playergamehistory.h"
#include "mainwindow.h"

namespace Ui {
class TopPlayersWindow;
}

class TopPlayersWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TopPlayersWindow(QWidget *parent = 0, PlayerGameHistory* pgh = 0,
                              MainWindow* menu = 0);
    ~TopPlayersWindow();
    void refresh();

private:
    Ui::TopPlayersWindow *ui;

    std::vector<Player*> top_players();

protected:
    MainWindow* menu;
    PlayerGameHistory* pgh;

    void closeEvent(QCloseEvent* event);

};

#endif // TOPPLAYERSWINDOW_H
