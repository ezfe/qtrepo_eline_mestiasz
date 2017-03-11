#include "selectplayerwindow.h"
#include "ui_selectplayerwindow.h"

SelectPlayerWindow::SelectPlayerWindow(QWidget *parent, PlayerGameHistory* pgh,
                                       MainWindow* menu) : QWidget(parent),
    ui(new Ui::SelectPlayerWindow){

    ui->setupUi(this);
    this->pgh = pgh;
    this->menu = menu;
}

SelectPlayerWindow::~SelectPlayerWindow()
{
    delete ui;
}

void SelectPlayerWindow::init_list(){
    QGroupBox* groupBox = new QGroupBox(tr("Players:"));
    QVBoxLayout* vbox = new QVBoxLayout;

    QRadioButton* playerButton = nullptr;
    QRadioButton* firstPlayer = nullptr;
    int i = 0;
    for(Player* player : pgh->get_players()){
        std::string fullName = player->get_first_name() + player->get_last_name();
        playerButton = new QRadioButton(tr(fullName.c_str()));
        if(i == 0) firstPlayer = playerButton;
        vbox->addWidget(playerButton);
        i++;
    }

    if(pgh->get_players().size() > 0){
        vbox->addStretch(1);
        groupBox->setLayout(vbox);
        firstPlayer->setChecked(true);
    }

    ui->playerList->setWidget(groupBox);

}

void SelectPlayerWindow::closeEvent(QCloseEvent *event){
    this->menu->show();
    event->accept();
}

void SelectPlayerWindow::on_SelectPlayerWindowButton_clicked()
{

}
