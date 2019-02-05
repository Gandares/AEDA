#pragma once

#include <iostream>

using namespace std;

class hormiga{
    
private:
    
    int direccion;
    int posicioni;
    int posicionj;
    
    
public:

    hormiga(int fil, int col, int direccion);
    void dirinicial(void);
    int get_direccion() const;
    int get_pos_i() const;
    int get_pos_j() const;
    void movimiento(char color, int dir, int fil, int col);
    
};