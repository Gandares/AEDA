#pragma once

#include "hormiga.hpp"

#include <cstdlib>
#include <iomanip>

class hormiga_t5: public hormiga{

public:

    hormiga_t5(int f, int c);
    void movimiento(char color);
    ostream& write(void);
    
};