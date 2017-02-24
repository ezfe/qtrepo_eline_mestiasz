#include "robotswindow.h"
#include "ui_robotswindow.h"

RobotsWindow::RobotsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RobotsWindow)
{
    ui->setupUi(this);

    this->engine = new Robots(20, 40, 7);
    this->refresh_gameboard();
}

RobotsWindow::~RobotsWindow()
{
    delete ui;
    delete engine;
}

void RobotsWindow::refresh_gameboard(){
    QString new_board = QString::fromStdString(this->engine->print_gameboard());

    ui->gameBoard->clear();
    ui->gameBoard->setText(new_board);
    ui->score->setText(QString::number(this->engine->get_score()));
}

void RobotsWindow::handle_event(char cmd){
    this->engine->controller(cmd);
    this->refresh_gameboard();
}


void RobotsWindow::on_yButton_clicked()
{
    this->handle_event('y');
}

void RobotsWindow::on_kButton_clicked()
{
    this->handle_event('k');
}

void RobotsWindow::on_uButton_clicked()
{
    this->handle_event('u');
}

void RobotsWindow::on_hButton_clicked()
{
    this->handle_event('h');
}

void RobotsWindow::on_lButton_clicked()
{
    this->handle_event('l');
}

void RobotsWindow::on_bButton_clicked()
{
    this->handle_event('b');
}

void RobotsWindow::on_jButton_clicked()
{
    this->handle_event('j');
}

void RobotsWindow::on_nButton_clicked()
{
    this->handle_event('n');
}

void RobotsWindow::on_wButton_clicked()
{
    this->handle_event('w');
}

void RobotsWindow::on_tButton_clicked()
{
    this->handle_event('t');
}

void RobotsWindow::on_qButton_clicked()
{
    this->handle_event('q');
}

void RobotsWindow::on_rButton_clicked()
{
    this->handle_event('r');
}

