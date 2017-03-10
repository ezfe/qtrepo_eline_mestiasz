#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "wormswindow.h"
#include "../gui_robots/robotswindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_playRobotsButton_clicked();

    void on_playWormsButton_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
