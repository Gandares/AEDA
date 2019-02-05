#pragma once

#include <iostream>
#include <cstdlib>
#include "hormiga.hpp"
#include "hormiga_t1.hpp"
#include "hormiga_t2.hpp"
#include "hormiga_t3.hpp"
#include "hormiga_t4.hpp"
#include "hormiga_t5.hpp"
#include "rejilla.hpp"

using namespace std;

class maquina{
    
private: 

    rejilla mapa;
    int pfil;
    int ffil;
    int pcol;
    int fcol;
    
    
public:

    void aleatorio(void);
    void paso(void);
    ostream& write(hormiga_t1 Hor1, hormiga_t2 Hor2, hormiga_t3 Hor3, hormiga_t4 Hor4, hormiga_t5 Hor5);
    
};
    