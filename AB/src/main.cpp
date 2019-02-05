#include "../include/AB.hpp"
#include "../include/dni.hpp"

#include <iostream>

using namespace std;

int main(){
    
    ArbolB arbol;
    int x, y;
    long int w;
    
    do{
        
        cout << endl << endl;
        cout << "1. Insertar." << endl;
        cout << "2. Eliminar." << endl;
        cout << "3. Buscar." << endl;
        cout << "0. Salir." <<endl;
        cout << "Elige una opción: ";
        cin >> x;
        
        switch(x){
            
            case 1: cout << "1. Generar DNI aleatorio." << endl;
                    cout << "2. Crear DNI." << endl;
                    cout << "Elige una opción: ";
                    cin >> y;
                    switch(y){
                        
                        case 1: arbol.insertar1(y);
                                break;
                        case 2: arbol.insertar1(y);
                                break;
                        default: cout << "Error en la opción." << endl;
                                 break;
                    }
                    break;
            
            case 2: cout << "¿Que DNI quiere borrar? ";
                    cin >> w;
                    arbol.eliminar(w,arbol.raiz());
                    break;
            
            case 3: cout << "¿Que DNI quiere buscar? ";
                    cin >> w;
                    arbol.buscar(arbol.raiz(),w);
                    break;
                    
            case 0: break;
            
            default: cout << "Opción errónea." << endl;
                     break;
                     
        }
        arbol.pornivel(arbol.raiz());
        cout << endl;
    }while(x!=0);
}
    