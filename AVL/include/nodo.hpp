#pragma once

#include "dni.hpp"

using namespace std;

class nodo{
    
    private:
    
        dni dato;
        nodo* izquierdo;
        nodo* derecho;
        int balance;
        
    public:
    
        nodo(dni dat, nodo* izq=NULL, nodo* dcho=NULL, int bal=0):
        dato(dat),
        izquierdo(izq),
        derecho(dcho),
        balance(bal)
        {}
        
        long int get_dato(){
            
            return dato.get_num();
        }
        
        dni get_dato(int x){
            
            return dato;
        }
        
        void set_dato(dni d){
            
            dato.set_num(d.get_num());
        }
        
        void set_dato(long int d){
            
            dato.set_num(d);
        }
        
        nodo*& get_izq(){
            
            return izquierdo;
        }
        
        void set_izq(nodo* n){
            
            izquierdo=n;
        }
        
        nodo*& get_dcho(){
            
            return derecho;
        }
        
        void set_dcho(nodo* n){
            
            derecho=n;
        }
        
        void set_balance(int b){
          
            balance = b;
        }
         
        int get_balance(void){
          
            return balance;
        }
};