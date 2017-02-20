#include "enginewindow.h"
#include "ui_enginewindow.h"

EngineWindow::EngineWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EngineWindow)
{
    ui->setupUi(this);
}

EngineWindow::~EngineWindow()
{
    delete ui;
}
