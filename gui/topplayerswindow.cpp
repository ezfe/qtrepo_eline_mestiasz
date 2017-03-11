#include "topplayerswindow.h"
#include "ui_topplayerswindow.h"

TopPlayersWindow::TopPlayersWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TopPlayersWindow)
{
    ui->setupUi(this);
}

TopPlayersWindow::~TopPlayersWindow()
{
    delete ui;
}
