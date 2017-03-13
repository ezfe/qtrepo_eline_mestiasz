#include "selectplayerwindow.h"
#include "ui_selectplayerwindow.h"

SelectPlayerWindow::SelectPlayerWindow(QWidget *parent, PlayerGameHistory* pgh,
                                       MainWindow* menu) : QWidget(parent),
    ui(new Ui::SelectPlayerWindow){

    ui->setupUi(this);
    this->pgh = pgh;
    this->menu = menu;
}

SelectPlayerWindow::~SelectPlayerWindow() {
    delete ui;
}

/*!
 * \brief Initialize the player list
 */
void SelectPlayerWindow::init_list(){
    QGroupBox* groupBox = new QGroupBox(tr("Players:"));
    QVBoxLayout* vbox = new QVBoxLayout();
    bgroup = new QButtonGroup(groupBox);
    bgroup->setExclusive(true);

    QRadioButton* playerButton = nullptr;
    QRadioButton* firstPlayer = nullptr;
    int i = 0;
    // Draw radio buttons with player names
    for(Player* player : pgh->get_players()){
        std::string fullName = player->get_first_name() + " " + player->get_last_name();
        playerButton = new QRadioButton(tr(fullName.c_str()));
        if(i == 0) firstPlayer = playerButton;
        vbox->addWidget(playerButton);
        bgroup->addButton(playerButton, i);
        i++;
    }
    // select the first player if there is one
    if(pgh->get_players().size() > 0){
        vbox->addStretch(1);
        groupBox->setLayout(vbox);
        firstPlayer->setChecked(true);
    }
    // add to the ui
    ui->playerList->setWidget(groupBox);

}

/*!
 * \brief Override close event
 */
void SelectPlayerWindow::closeEvent(QCloseEvent *event){
    if(pgh->get_players().size() > 0){
        menu->currentPlayer = pgh->get_players().at(bgroup->checkedId());
    }
    this->menu->show();
    event->accept();
}

/*!
 * \brief Handle select button
 */
void SelectPlayerWindow::on_select_clicked() {
    this->close();
}
