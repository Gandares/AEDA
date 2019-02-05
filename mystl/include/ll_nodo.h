#include "array.h"
#include <cassert>
#include <iostream>
#include <cstdio>

using namespace std;

template <class T>
    class  nodo{

private:

    vector_<T> next_;                                                           //Siguiente dato
    T          data_;                                                           //Dato
    
public:

    nodo(void):                                                                 //Constructores
    next_(NULL),
    data_()
    {}
    
    nodo(T& dato):
    next_(NULL),
    data_(dato)
    {}
    
    ~nodo(){                                                                    //Destructor
        next_=NULL;
    }
    
    nodo<T>* get_next(void){                                                    //Devolver siguiente
        return next_;
    }
    
    void set_next(nodo<T>* next){                                               //Cambiar el siguiente
        next_=next;
    }
    
    T get_data(void){                                                           //Devolver dato
        return data_;
    }
    
    void set_data(T dato){                                                      //Cambiar dato
        data_=dato;
    }
};
