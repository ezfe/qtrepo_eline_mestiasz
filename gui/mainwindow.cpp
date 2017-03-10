#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_playRobotsButton_clicked() {
    RobotsWindow* robots = new RobotsWindow();
    robots->show();
}

void MainWindow::on_playWormsButton_clicked() {
    WormsWindow* worms = new WormsWindow();
    worms->show();
}
