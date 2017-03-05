#include "newplayer.h"

NewPlayer::NewPlayer(PlayerGameHistory* pgh) : MenuItemScreen(){
    this->pgh = pgh;
}

NewPlayer::~NewPlayer(){

//    for(auto f : field){
//        if(f != nullptr)
//        delete f;
//    }

//    if(my_form != nullptr) delete my_form;
}

void NewPlayer::init_form(){
    field[0] = new_field(1, 17, 4, 22, 0, 0);
    field[1] = new_field(1, 17, 6, 22, 0, 0);
    field[2] = new_field(1, 17, 8, 22, 0, 0);
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

void NewPlayer::controller(){
    init_form();
    continue_looping = true;

    do {
       int ch = getch();
       switch(ch){
       case KEY_DOWN:
           form_driver(my_form, REQ_NEXT_FIELD);
           form_driver(my_form, REQ_END_LINE);
           break;
       case KEY_UP:
           form_driver(my_form, REQ_PREV_FIELD);
           form_driver(my_form, REQ_END_LINE);
           break;
       case KEY_LEFT:
           continue_looping = false;
           form_driver(my_form, REQ_END_LINE);
           submit_form();
           break;
       default:
           form_driver(my_form, ch);
           break;
       }
    } while (continue_looping);
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
