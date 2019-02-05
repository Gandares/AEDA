#include "../include/AVL.hpp"
#include "../include/dni.hpp"

#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    ArbolAVL AVL;
    bool doe;
    int x, sel, tam, npruebas, dummy;
    long int w, y, z;
    
    cout << "1. Demostrativo." << endl;
    cout << "2. Estadisctico." << endl;
    cout << "Elige una opcion: ";
    cin >> sel;
    
    if(sel==1){
    
    do{
        
        doe=true;
        cout << endl << endl;
        cout << "1. Insertar." << endl;
        cout << "2. Eliminar." << endl;
        cout << "3. Buscar." << endl;
        cout << "0. Salir." <<endl;
        cout << "Elige una opción: ";
        cin >> x;
        
        switch(x){
            
            case 1: cout << "Introduzca DNI (8 cifras): ";
                    cin >> y;
                    AVL.insertar(y);
                    AVL.pornivel();
                    cout << endl;
                    break;
            
            case 2: cout << "¿Que DNI quiere borrar? ";
                    cin >> w;
                    AVL.eliminar(w);
                    AVL.pornivel();
                    cout << endl;
                    break;
            
            case 3: cout << "¿Que DNI quiere buscar? ";
                    cin >> z;
                    AVL.buscar(AVL.raiz(),z,dummy,doe);
                    AVL.pornivel();
                    cout << endl;
                    break;
            
            case 0: break;
            
            default: cout << "Opción errónea." << endl;
                     break;
                     
        }
    }while(x!=0);
    }
    else if(sel==2){
        
        doe=false;
        cout << "Tamaño del árbol: ";
        cin >> tam;
        cout << "Numero de pruebas: ";
        cin >> npruebas;
        
        vector<dni> vp(2*tam);
        
        for(int i=0; i<tam; i++)
            AVL.insertar(vp[i]);
        dni DNI = vp[0];
        
        int contador=0;
        vector<int> val;
        
        for(int j=tam; j<tam+npruebas; j++){
            AVL.buscar(AVL.raiz(),vp[j].get_num(),contador,doe);
            val.push_back(contador);
            contador=0;
        }
        
        //No pertenecientes
        cout << "            Tamaño   Pruebas     Mínimo      Media     Máximo" << endl;
        cout << "Insercion   " << tam << "    " << npruebas << "           ";
        
        int min=val[0];
        int max=val[0];
        int acumulador=0;
        float media=0.0;        
        
        for(int i=1; i<val.size(); i++){
            if(val[i]<min)
                min=val[i];
            if(val[i]>max)
                max=val[i];
            acumulador+=val[i];
        }
        media=acumulador/val.size();
    
        
        cout << min << "         " << media << "         " << max << endl;

        contador = 0;
        val.clear();
        
        for(int i=0; i<npruebas; i++){

            AVL.buscar(AVL.raiz(),vp[i].get_num(),contador,doe);
            val.push_back(contador);
            contador=0;
        }
        
        //Pertenecientes
        cout << "Busqueda    " << tam << "    " << npruebas << "           ";
        
        min=val[0];
        max=val[0];
        acumulador=0;
        media=0.0;        
        
        for(int i=1; i<val.size(); i++){
            if(val[i]<min)
                min=val[i];
            if(val[i]>max)
                max=val[i];
            acumulador+=val[i];
        }
        media=acumulador/val.size();
    
        
        cout << min << "         " << media << "         " << max << endl;

    }

}
    