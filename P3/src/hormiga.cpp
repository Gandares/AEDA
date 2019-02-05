#include "../include/hormiga.hpp"

hormiga::hormiga(int f, int c):
posicioni(f),
posicionj(c),
direccion(1)
{}

int hormiga::get_pos_i(void){
    
    return posicioni;
}

int hormiga::get_pos_j(void){
    
    return posicionj;
}

