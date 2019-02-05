#pragma once

#include "nodo.hpp"
#include "dni.hpp"

#include <queue>
#include <iostream>

using namespace std;

class ArbolB{
    
    private:
    
        nodo* raiz_;
    
    public:
        
        ArbolB(void): raiz_(NULL){}
        ArbolB(nodo* r): raiz_(r){}
        ~ArbolB() { podar(raiz_); }
        nodo* raiz() const;
        nodo*& raiz();
        bool empty() const;
        nodo* minimo(nodo* t);
        void pornivel(nodo* node);
        void insertar(nodo* &node, dni key);
        void insertar1(int opcion);
        void buscar(nodo* node, long int key) const;
        void eliminar(dni key, nodo* &t);
        void podar(nodo* &node);
};