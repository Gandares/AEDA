#pragma once

#include "hormiga.hpp"

#include <cstdlib>
#include <iomanip>

class hormiga_t3: public hormiga{

public:

    hormiga_t3(int f, int c);
    void movimiento(char color);
    ostream& write(void);
    
};
