#ifndef ENGINEWINDOW_H
#define ENGINEWINDOW_H

#include <QWidget>
#include "../engines/engine.h"
#include "../engines/worms.h"

namespace Ui {
class EngineWindow;
}

class EngineWindow: public QWidget {
    Q_OBJECT

public:
    explicit EngineWindow(QWidget *parent = 0);
    ~EngineWindow();

private slots:
    void on_upButton_clicked();

    void on_downButton_clicked();

    void on_rightButton_clicked();

    void on_leftButton_clicked();

    void on_resetGameboard_clicked();

private:
    Ui::EngineWindow *ui;

    Engine * engine;

    void refresh_gameboard();
};

#endif // ENGINEWINDOW_H
