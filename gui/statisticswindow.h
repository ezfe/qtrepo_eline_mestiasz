#ifndef STATISTICSWINDOW_H
#define STATISTICSWINDOW_H

#include <QWidget>
#include <QCloseEvent>

#include "../game_history/playergamehistory.h"
#include "mainwindow.h"

class MainWindow;

namespace Ui {
class StatisticsWindow;
}

class StatisticsWindow : public QWidget {
    Q_OBJECT

public:
    explicit StatisticsWindow(QWidget *parent = 0, PlayerGameHistory* pgh = 0,
                              MainWindow* menu = 0);
    ~StatisticsWindow();

    void refresh();

private:
    Ui::StatisticsWindow *ui;

protected:
    MainWindow* menu;
    PlayerGameHistory* pgh;

    void closeEvent(QCloseEvent* event);
};

#endif // STATISTICSWINDOW_H
