#include "newplayer.h"

NewPlayer::NewPlayer() : MenuItemScreen(){
    field[0] = new_field(1, 10, 4, 18, 0, 0);
    field[1] = new_field(1, 10, 6, 18, 0, 0);
}

NewPlayer::~NewPlayer(){

}
