#include "addplayerwindow.h"
#include "ui_addplayerwindow.h"

AddPlayerWindow::AddPlayerWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddPlayerWindow)
{
    ui->setupUi(this);
}

AddPlayerWindow::~AddPlayerWindow()
{
    delete ui;
}
