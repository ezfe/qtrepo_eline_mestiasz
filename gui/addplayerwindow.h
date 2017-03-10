#ifndef ADDPLAYERWINDOW_H
#define ADDPLAYERWINDOW_H

#include <QWidget>
#include <iostream>
#include "../game_history/playergamehistory.h"

namespace Ui {
    class AddPlayerWindow;
}

class AddPlayerWindow : public QWidget {
    Q_OBJECT

public:
    explicit AddPlayerWindow(QWidget *parent = 0);
    ~AddPlayerWindow();

    void clearFields();
    void setPGH(PlayerGameHistory* pgh);
private slots:
    void on_addPlayerButton_clicked();

private:
    Ui::AddPlayerWindow *ui;
    PlayerGameHistory* pgh;
};

#endif // ADDPLAYERWINDOW_H
