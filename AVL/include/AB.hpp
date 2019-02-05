#pragma once

#include "nodo.hpp"
#include "dni.hpp"

#include <queue>
#include <iostream>

using namespace std;

class nodoAVL;

class ArbolB{
    
    public:
        
        nodo* raiz_;
        ArbolB(void): raiz_(NULL){}
        ArbolB(nodo* r): raiz_(r){}
        ~ArbolB() { podar(raiz_); }
        nodo* raiz() const;
        nodo*& raiz();
        bool empty() const;
        nodo* minimo(nodo* t);
        virtual void pornivel();
        void insertar1(nodo* &node, dni key);
        virtual void insertar(long int n);
        virtual void buscar(nodo* node, long int key, int& cont, bool doe) const;
        virtual void eliminar(dni key, nodo* &t);
        void podar(nodo* &node);
};