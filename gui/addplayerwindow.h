#ifndef ADDPLAYERWINDOW_H
#define ADDPLAYERWINDOW_H

#include <QWidget>
#include <iostream>

#include "mainwindow.h"
#include "../game_history/playergamehistory.h"

class MainWindow;

namespace Ui {
    class AddPlayerWindow;
}

class AddPlayerWindow : public QWidget {
    Q_OBJECT

public:
    explicit AddPlayerWindow(QWidget *parent = 0, PlayerGameHistory* pgh = 0, MainWindow* menu = 0);
    ~AddPlayerWindow();

    void clear_fields();
    void set_pgh(PlayerGameHistory* pgh);
    void set_menu(MainWindow* menu);

private slots:
    void on_addPlayerButton_clicked();

private:
    Ui::AddPlayerWindow *ui;
protected:
    MainWindow* menu;
    PlayerGameHistory* pgh;
};

#endif // ADDPLAYERWINDOW_H
