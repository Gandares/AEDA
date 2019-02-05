#pragma once

#include "hormiga.hpp"

#include <cstdlib>
#include <iomanip>

class hormiga_t4: public hormiga{

public:

    hormiga_t4(int f, int c);
    void movimiento(char color);
    ostream& write(void);
    
};