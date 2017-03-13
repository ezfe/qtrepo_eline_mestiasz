#include "wormswindow.h"
#include "ui_wormswindow.h"

WormsWindow::WormsWindow(QWidget *parent, PlayerGameHistory* pgh,
                         Player* player, MainWindow* menu): QWidget(parent), ui(new Ui::WormsWindow) {
    ui->setupUi(this);

    this->pgh = pgh;
    this->player = player;
    this->menu = menu;
    this->engine = new Worms(30, 44);
    this->refresh_gameboard();
    this->name = "Worms";
}

WormsWindow::~WormsWindow() {
    delete ui;
    delete engine;
}

/*!
 * \brief refresh gameboard and display new state
 */
void WormsWindow::refresh_gameboard() {
    // create an empty string
    QString temp_board = QString::fromStdString(engine->print_gameboard());

    // for debugging
    // std::cerr << temp_board.toStdString() << "\n";

    // clear the board
    ui->gameView->clear();

    if (this->engine->is_game_finished()) {
        ui->gameView->setText("You died. Your final score is " + QString::number(this->engine->get_score()) + ".\nPress \"Reset\" to play again.");
    } else {
        ui->gameView->setText(temp_board);
    }

    ui->scoreLabel->setText(QString::number(engine->get_score()));
}

void WormsWindow::on_resetGame_clicked() {
    this->save_game();
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

/*!
 * \brief Store the game in PlayerGameHistory
 */
void WormsWindow::save_game(){
    Game* game = new Game(player, name, engine->get_score());
    pgh->add_game(player, game);
}

/*!
 * \brief Override close event
 */
void WormsWindow::closeEvent(QCloseEvent *event){
    save_game();
    this->menu->show();
    event->accept();
}
