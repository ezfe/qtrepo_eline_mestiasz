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

/*!
 * \brief initialize pgh container
 * \param PlayerGameHistory* pgh
 */
void AddPlayerWindow::set_pgh(PlayerGameHistory* pgh) {
    this->pgh = pgh;
}

/*!
 * \brief initialize menu
 * \param MainWindow* menu
 */
void AddPlayerWindow::set_menu(MainWindow* menu) {
    this->menu = menu;
}

/*!
 * \brief Empty all the textfields
 */
void AddPlayerWindow::clear_fields() {
    ui->addPlayerFirstName->clear();
    ui->addPlayerLastName->clear();
    ui->addPlayerAddress->clear();
}

/*!
 * \brief Create and add new player to pgh
 */
void AddPlayerWindow::on_addPlayerButton_clicked() {
    std::string firstName = ui->addPlayerFirstName->text().toStdString();
    std::string lastName = ui->addPlayerLastName->text().toStdString();
    std::string address = ui->addPlayerAddress->text().toStdString();

    std::cout << "Made player " << firstName << " " << lastName << " @ " << address << std::endl;
    if (this->pgh != nullptr) {
        // add player to pgh
        this->pgh->add_player(firstName, lastName, address);
        std::cout << "Saved to PGH object" << std::endl;
    } else {
        std::cerr << "No PlayerGameHistory object" << std::endl;
    }

    this->menu->show();
    this->close();
}
