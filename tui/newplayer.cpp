#include "newplayer.h"

NewPlayer::NewPlayer(PlayerGameHistory* pgh) : MenuItemScreen(){
    this->pgh = pgh;
}

NewPlayer::~NewPlayer(){
    for(auto f : field){
        delete f;
    }
}

void NewPlayer::init_form(){
    field[0] = new_field(1, 10, 4, 22, 0, 0);
    field[1] = new_field(1, 10, 6, 22, 0, 0);
    field[2] = new_field(1, 10, 8, 22, 0, 0);
    field[3] = NULL;

    set_field_back(field[0], A_UNDERLINE);
    set_field_back(field[1], A_UNDERLINE);
    set_field_back(field[2], A_UNDERLINE);


    field_opts_off(field[0], O_AUTOSKIP);
    field_opts_off(field[1], O_AUTOSKIP);
    field_opts_off(field[1], O_AUTOSKIP);

    my_form = new_form(field);
    post_form(my_form);

    refresh();

    mvprintw(4, 10, "Firstname: ");
    mvprintw(6, 10, "Lastname: ");
    mvprintw(8, 10, "Address: ");

    refresh();
}

void NewPlayer::submit_form(){
    unpost_form(my_form);
    free_form(my_form);
    std::string firstname = field_buffer(field[0], 0);
    std::string lastname = field_buffer(field[1], 0);
    std::string address = field_buffer(field[2], 0);

    free_field(field[0]);
    free_field(field[1]);
    free_field(field[2]);

    pgh->add_player(firstname, lastname, address);

}
