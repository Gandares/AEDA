#include "metodos.hpp"
#include "dni.hpp"

#include <cstdlib>

using namespace std;

int main(void){
    
    int tamano;
    
    cout << "Seleccione el tamaño para la demostración de los métodos de ordenación: ";
    cin >> tamano;
    
    dni DNI;
    vector<int> v1(tamano);
    vector<int> v2(1000);
    int opcion,seed;
    int npruebas=100;
    double med=0;
do{
    cout << "1. Modo demostración: insertion." << endl;
    cout << "2. Modo demostración: bubble." << endl;
    cout << "3. Modo demostración: heapsort." << endl;
    cout << "4. Modo demostración: quicksort." << endl;
    cout << "5. Modo demostración: shellsort." << endl;
    cout << "6. Modo estadístico." << endl;
    cout << "7. Salir." << endl;
    cout << "Elija una opción: ";
    cin >> opcion;
    
    switch(opcion){
        
        case 1: DNI.rellenar(v1);
                cin.get();
                insertion_sort(v1,1);
                break;
                
        case 2: DNI.rellenar(v1);
                cin.get();
                bubble_sort(v1,1);
                break;
                
        case 3: DNI.rellenar(v1);
                cin.get();
                heap_sort(v1,1);
                break;
                
        case 4: DNI.rellenar(v1);
                cin.get();
                quick_sort(v1,0,v1.size()-1,1);
                break;
                
        case 5: DNI.rellenar(v1);
                cin.get();
                shell_sort(v1,1);
                break;
                
        case 6: seed=DNI.semilla();
                cout << "            Mínimo        Media              Máximo" << endl;
                cout << "Insertion  ";
                for(int k=0;k<npruebas;k++){
                DNI.rellenar_semilla(v2,seed);
                seed++;
                insertion_sort(v2,0);
                set_datos();
                }
                write_mmm(npruebas);
                seed-=npruebas;
                cout << "Bubble     ";
                for(int k=0;k<npruebas;k++){
                DNI.rellenar_semilla(v2,seed);
                seed++;
                bubble_sort(v2,0);
                set_datos();
                }
                write_mmm(npruebas);
                seed-=npruebas;
                cout << "heap_sort  ";
                for(int k=0;k<npruebas;k++){
                DNI.rellenar_semilla(v2,seed);
                seed++;
                heap_sort(v2,0);
                set_datos();
                }
                write_mmm(npruebas);
                seed-=npruebas;
                cout << "quick_sort ";
                for(int k=0;k<npruebas;k++){
                DNI.rellenar_semilla(v2,seed);
                seed++;
                quick_sort(v2,0,v2.size()-1,0);
                set_datos();
                }
                write_mmm(npruebas);
                seed-=npruebas;
                cout << "shell_sort ";
                for(int k=0;k<npruebas;k++){
                DNI.rellenar_semilla(v2,seed);
                seed++;
                shell_sort(v2,0);
                set_datos();
                }
                write_mmm(npruebas);
                seed-=npruebas;
                break;
                
        case 7: break;
        
        default:
                cout << endl << "Error en la selección." << endl << endl;
                break;
                
        }
    }while(opcion!=7);
}