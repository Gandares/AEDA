#pragma once

#include <iostream>

using namespace std;

class hormiga{
    
protected:
    
    int direccion;
    int posicioni;
    int posicionj;
    
public:

    hormiga(int f, int c);
    
    virtual int get_pos_i();
    virtual int get_pos_j();
    virtual void movimiento(char color)=0;
    virtual ostream& write(void)=0;
    
};