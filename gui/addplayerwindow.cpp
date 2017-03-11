#include "addplayerwindow.h"
#include "ui_addplayerwindow.h"

AddPlayerWindow::AddPlayerWindow(QWidget *parent, PlayerGameHistory* pgh, MainWindow* menu):
    QWidget(parent), ui(new Ui::AddPlayerWindow) {
    ui->setupUi(this);

    this->pgh = pgh;
    this->menu = menu;
}

AddPlayerWindow::~AddPlayerWindow() {
    delete ui;
}

void AddPlayerWindow::set_pgh(PlayerGameHistory* pgh) {
    this->pgh = pgh;
}

void AddPlayerWindow::set_menu(MainWindow* menu) {
    this->menu = menu;
}

void AddPlayerWindow::clear_fields() {
    ui->addPlayerFirstName->clear();
    ui->addPlayerLastName->clear();
    ui->addPlayerAddress->clear();
}

void AddPlayerWindow::on_addPlayerButton_clicked() {
    std::string firstName = ui->addPlayerFirstName->text().toStdString();
    std::string lastName = ui->addPlayerLastName->text().toStdString();
    std::string address = ui->addPlayerAddress->text().toStdString();

    std::cout << "Made player " << firstName << " " << lastName << " @ " << address << std::endl;
    if (this->pgh != nullptr) {
        this->pgh->add_player(firstName, lastName, address);
        std::cout << "Saved to PGH object" << std::endl;
    } else {
        std::cerr << "No PlayerGameHistory object" << std::endl;
    }

    this->menu->show();
    this->close();
}
