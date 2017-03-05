#include "menuitemscreen.h"

MenuItemScreen::MenuItemScreen(PlayerGameHistory* pgh){
    this->pgh = pgh;
}

MenuItemScreen::~MenuItemScreen(){

}

void MenuItemScreen::init(){
    this->controller();
}


