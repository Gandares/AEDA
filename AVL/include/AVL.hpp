#include "AB.hpp"
#include "nodoAVL.hpp"

#include <iostream>

using namespace std;

class nodoB;

class ArbolAVL : public ArbolB{
        
    public:
    
        ArbolAVL(void){ ArbolB::raiz_=NULL; }
        ~ArbolAVL(){ ArbolB::podar(ArbolB::raiz_); } 
        void insertar(dni DNI);
        void sustituye(nodo* &eliminado, nodo* &sustituto, bool &decrece);
        void eliminar(long int num);
    
    private: 
    
        void i_bal(nodo* &n1, nodo* n2, bool& crece);
        void i_balancea_izq(nodo* &n, bool& crece);
        void i_balancea_dcha(nodo* &n, bool& crece);
        
        void eliminar_rama(nodo* &r, dni DNI, bool& decrece);
        void e_balancea_izq(nodo* &n, bool& decrece);
        void e_balancea_dcha(nodo* &n, bool& decrece);
        
        void rotar_II(nodo* &n);
        void rotar_DD(nodo* &n);
        void rotar_ID(nodo* &n);
        void rotar_DI(nodo* &n);
    
};