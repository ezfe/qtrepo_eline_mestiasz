#include "baseclass.h"

int BaseClass::id_cnt = 0;

BaseClass::BaseClass(){
    id = id_cnt;
    id_cnt++;

    SHOW_WHERE;

}
