#ifndef WORMSWINDOW_H
#define WORMSWINDOW_H

#include <QWidget>
#include "../engines/engine.h"
#include "../engines/worms.h"

namespace Ui {
class WormsWindow;
}

class WormsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit WormsWindow(QWidget *parent = 0);
    ~WormsWindow();

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
};

#endif // WORMSWINDOW_H
