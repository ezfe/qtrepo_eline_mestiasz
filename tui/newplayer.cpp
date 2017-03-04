#include "newplayer.h"

NewPlayer::NewPlayer() : MenuItemScreen(){

}

NewPlayer::~NewPlayer(){
    for(auto f : field){
        delete f;
    }
}

void NewPlayer::init_form(){
    field[0] = new_field(1, 10, 4, 18, 0, 0);
    field[1] = new_field(1, 10, 6, 18, 0, 0);
    field[2] = NULL;

    set_field_back(field[0], A_UNDERLINE);
    set_field_back(field[1], A_UNDERLINE);

    field_opts_off(field[0], O_AUTOSKIP);
    field_opts_off(field[1], O_AUTOSKIP);

    my_form = new_form(field);
    post_form(my_form);

    refresh();

    mvprintw(4, 10, "Value 1:");
    mvprintw(6, 10, "Value 2:");

    refresh();
}
