#include "hormiga.hpp"

hormiga::hormiga(int fil, int col, int dir){
    
    posicioni=fil;
    posicionj=col;
    direccion=dir;
}


int hormiga::get_direccion(void) const{
    
    return direccion;
}

int hormiga::get_pos_i(void) const{
    
    return posicioni;
}

int hormiga::get_pos_j(void) const{
    
    return posicionj;
}

void hormiga::movimiento(char color, int dir, int fil, int col){
    
    if(color==' ')
        color='X';
    else
        color=' ';
        
    if(color==' '){
        direccion=dir-1;
        if(direccion==0)
            direccion=4;
    }
    if(color=='X'){
        direccion=dir+1;
        if(direccion==5)
            direccion=1;
    }
        
        if(direccion==1)        //^
            posicioni=fil-1;
        if(direccion==2)        //>
            posicionj=col+1;
        if (direccion==3)       //v
            posicioni=fil+1;
        if(direccion==4)        //<
            posicionj=col-1;
            
}