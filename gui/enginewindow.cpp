#include "enginewindow.h"
#include "ui_enginewindow.h"

EngineWindow::EngineWindow(QWidget *parent): QWidget(parent), ui(new Ui::EngineWindow) {
    ui->setupUi(this);

    this->engine = new Worms(20, 20);

    this->refresh_gameboard();
}

EngineWindow::~EngineWindow() {
    delete ui;
}

void EngineWindow::refresh_gameboard() {
    // create an empty string
    QString temp_board = QString::fromStdString(engine->print_gameboard());

    // for debugging
    // std::cerr << temp_board.toStdString() << "\n";

    // clear the board
    ui->gameboardLabel->clear();

    // load the QString into the label
    ui->gameboardLabel->setText(temp_board);
}

void EngineWindow::on_upButton_clicked() {
    engine->controller('j');
    refresh_gameboard();
}

void EngineWindow::on_downButton_clicked() {
    engine->controller('k');
    refresh_gameboard();
}

void EngineWindow::on_rightButton_clicked() {
    engine->controller('l');
    refresh_gameboard();
}

void EngineWindow::on_leftButton_clicked() {
    engine->controller('h');
    refresh_gameboard();
}

void EngineWindow::on_resetGameboard_clicked() {
    engine->reset_game();
    refresh_gameboard();
}
