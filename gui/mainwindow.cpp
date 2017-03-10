#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
<<<<<<< HEAD
    pgh = new PlayerGameHistory();
=======
    ui->addPlayerFields->hide();
>>>>>>> origin/master
}

MainWindow::~MainWindow() {
    delete ui;
    if(pgh != nullptr) delete pgh;
}

void MainWindow::on_playRobotsButton_clicked() {
    RobotsWindow* robots = new RobotsWindow();
    robots->show();
}

void MainWindow::on_playWormsButton_clicked() {
    WormsWindow* worms = new WormsWindow();
    worms->show();
}

void MainWindow::on_exit_triggered() {

}

void MainWindow::on_topPlayers_triggered()
{

}

void MainWindow::on_topGames_triggered()
{


}

void MainWindow::on_newPlayer_triggered() {
    ui->addPlayerFields->show();
}

void MainWindow::on_addPlayerButton_clicked() {
    std::string firstName = ui->addPlayerFirstName->text().toStdString();
    std::string lastName = ui->addPlayerFirstName->text().toStdString();
    std::string address = ui->addPlayerFirstName->text().toStdString();

    std::cout << "Made player " << firstName << " " << lastName << " @ " << address << std::endl;
}
