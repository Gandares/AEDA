#include "ll_nodo.h"
#include <cassert>
#include <iostream>
#include <cstdio>

using namespace std;

template <class T>
    class ll{
        
private:

    nodo<T>*     head_;                                                         //kbsa de la lista
    int            sz_;

public:

    ll(void):                                                                   //Constructor
    head_(NULL),
    sz_(0)
    {}

    ~ll(void){                                                                  //Destructor
    nodo<T>* aux = NULL;

    while (head_ != NULL) {
        aux = head_;
        head_ = head_->get_next();
        delete aux;
        aux = NULL;
    }
    head_=NULL;
    }

    void insert_head(nodo<T>* n){                                               //Meter dato
    n->set_next(head_);
    head_ = n;          
    }

    void insert_after(nodo<T>* prev, nodo<T>* n){                               //Insertar dato entre
    n->set_next(prev->get_next());
    prev->set_next(n);
    }

    nodo<T>* extract_head(void){                                                //Extraer dato de la kbsa
    nodo<T>* aux = head_;
    head_ = head_->get_next();
    aux->set_next(NULL);
    return aux;  // (3)
    }

    nodo<T>* extract_after(nodo<T>* prev){                                      //Extraer dato entre
    nodo<T>* aux = prev->get_next();
    prev->set_next(aux->get_next());
    aux->set_next(NULL);
    return aux;
    }
};
