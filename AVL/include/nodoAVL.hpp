#include "nodo.hpp"
#include "dni.hpp"

using namespace std;

class nodo;

class nodoAVL : public nodo{
    
    private:
    
        int balance;
    
    public:
    
        nodoAVL(const dni dat, nodoAVL *izq=NULL, nodoAVL *der=NULL, int bal=0):
        nodo(dat, izq, der),
        balance(bal){}
         
        void set_balance(int b){
          
            balance = b;
        }
         
        int get_balance(void){
          
            return balance;
        }
};