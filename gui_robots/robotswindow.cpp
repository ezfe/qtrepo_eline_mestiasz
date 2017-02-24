#include "robotswindow.h"
#include "ui_robotswindow.h"

RobotsWindow::RobotsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RobotsWindow)
{
    ui->setupUi(this);
}

RobotsWindow::~RobotsWindow()
{
    delete ui;
}
