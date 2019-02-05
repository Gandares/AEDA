#pragma once

#include <iostream>
#include <cstdlib>
#include "hormiga.hpp"
#include "rejilla.hpp"

using namespace std;

class maquina{
    
private: 

    rejilla mapa;
    char doblehormiga;
    int trans_direccion;
    int fila;
    int columna;
    int trans_direccion2;   //Para la segunda hormiga
    int fila2;              //Para la segunda hormiga
    int columna2;           //Para la segunda hormiga
    int pfil;
    int ffil;
    int pcol;
    int fcol;
    
    
public:

    void inicio(void);
    void aleatorio(void);
    void paso(void);
    ostream& write(void);
    
};
    