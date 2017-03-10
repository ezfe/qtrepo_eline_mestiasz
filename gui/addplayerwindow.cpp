#include "addplayerwindow.h"
#include "ui_addplayerwindow.h"

AddPlayerWindow::AddPlayerWindow(QWidget *parent): QWidget(parent), ui(new Ui::AddPlayerWindow) {
    ui->setupUi(this);
}

AddPlayerWindow::~AddPlayerWindow()
{
    delete ui;
}

void AddPlayerWindow::clearFields() {
    ui->addPlayerFirstName->clear();
    ui->addPlayerLastName->clear();
    ui->addPlayerAddress->clear();
}

void AddPlayerWindow::on_addPlayerButton_clicked() {
    std::string firstName = ui->addPlayerFirstName->text().toStdString();
    std::string lastName = ui->addPlayerLastName->text().toStdString();
    std::string address = ui->addPlayerAddress->text().toStdString();

//    pgh->add_player(firstName, lastName, address);
    std::cout << "Made player " << firstName << " " << lastName << " @ " << address << std::endl;

    this->close();
}
