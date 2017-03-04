#include "menuitemscreen.h"

MenuItemScreen::MenuItemScreen(){
    //my_form = new_form(nullptr);
}

MenuItemScreen::~MenuItemScreen(){
    delete my_form;
}

void MenuItemScreen::init(){
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
           break;
       default:
           form_driver(my_form, ch);
           break;
       }
    } while (continue_looping);
}


