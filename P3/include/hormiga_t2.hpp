#pragma once

#include "hormiga.hpp"

#include <cstdlib>
#include <iomanip>

class hormiga_t2: public hormiga{

public:

    hormiga_t2(int f, int c);
    void movimiento(char color);
    ostream& write(void);
    
};
