#include "wormswindow.h"
#include "ui_wormswindow.h"

WormsWindow::WormsWindow(QWidget *parent): QWidget(parent), ui(new Ui::WormsWindow) {
    ui->setupUi(this);

    this->engine = new Worms(40, 40);
    this->refresh_gameboard();
}

WormsWindow::~WormsWindow() {
    delete ui;
    delete engine;
}

void WormsWindow::refresh_gameboard() {
    // create an empty string
    QString temp_board = QString::fromStdString(engine->print_gameboard());

    // for debugging
    // std::cerr << temp_board.toStdString() << "\n";

    // clear the board
    ui->gameView->clear();

    // load the QString into the label
    ui->gameView->setText(temp_board);

    ui->scoreLabel->setText(QString::number(engine->get_score()));
}

void WormsWindow::on_resetGame_clicked() {
    this->engine->reset_game();
    this->refresh_gameboard();
}

void WormsWindow::on_upButton_clicked() {
    if (QApplication::keyboardModifiers().testFlag(Qt::ShiftModifier)) {
        this->engine->controller('W');
    } else {
        this->engine->controller('w');
    }
    this->refresh_gameboard();
}

void WormsWindow::on_downButton_clicked() {
    if (QApplication::keyboardModifiers().testFlag(Qt::ShiftModifier)) {
        this->engine->controller('S');
    } else {
        this->engine->controller('s');
    }
    this->refresh_gameboard();
}

void WormsWindow::on_rightButton_clicked() {
    if (QApplication::keyboardModifiers().testFlag(Qt::ShiftModifier)) {
        this->engine->controller('D');
    } else {
        this->engine->controller('d');
    }
    this->refresh_gameboard();
}

void WormsWindow::on_leftButton_clicked() {
    if (QApplication::keyboardModifiers().testFlag(Qt::ShiftModifier)) {
        this->engine->controller('A');
    } else {
        this->engine->controller('a');
    }
    this->refresh_gameboard();
}
