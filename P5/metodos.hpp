#include <iostream>
#include <cstdio>
#include <iomanip>
#include <vector>
 
int minimo=999999999;
int maximo=0;
double media=0;
int contador=0;
int acumulador=0;
 
using namespace std;

template<class Clave>      
ostream& write(ostream& os, vector<Clave>& v){
            for(int j=0;j<v.size();j++)
                os << v[j] << ", ";
            os << endl << endl;
            return os;
}

template<class Clave>       
void insertion_sort(vector<Clave>& v, int demostrar){
    
        int aux, pos;

        for (int i = 0; i < v.size(); i++){
            
            pos=i;
            aux=v[i];
            
            while((pos > 0)&&(v[pos-1]>aux)){
                v[pos]=v[pos-1];
                pos--;
                contador++;
            }
            v[pos]=aux;
            if(demostrar==1){
                write(cout,v);
                cin.get();
            }
        }
}

template<class Clave>        
void bubble_sort(vector<Clave>& v, int demostrar){
            
            int aux;
            
            for(int i=0;i<v.size();i++){
                for(int j=0;j<v.size();j++){
                    if(v[j]>v[j+1]){
                        aux=v[j];
                        v[j]=v[j+1];
                        v[j+1]=aux;
                    }
                    contador++;
                }
                if(demostrar==1){
                write(cout,v);
                cin.get();
                }
            }
        }

template<class Clave>    
void heapify(vector<Clave>& v, int n, int i){
            
            int largest = i;
            int l = 2*i + 1;
            int r = 2*i + 2;
         
            if (l < n && v[l] > v[largest])
                largest = l;
                contador++;
            if (r < n && v[r] > v[largest])
                largest = r;
                contador++;
            if (largest != i){
                swap(v[i],v[largest]);
                heapify(v,n,largest);
            }
            contador++;
        }

template<class Clave>    
void heap_sort(vector<Clave>& v, int demostrar){
            
            for (int i = v.size() / 2 - 1; i >= 0; i--){
                heapify(v, v.size(), i);
                if(demostrar==1){
                    write(cout,v);
                    cin.get();
                }
            }
                
            for (int i=v.size()-1; i>=0; i--){
                swap(v[0], v[i]);
                heapify(v, i, 0);
                if(demostrar==1){
                    write(cout,v);
                    cin.get();
                }
            }
        }
        
template<class Clave>    
int particion(vector<Clave>& v, int low, int high){
            
            int pivot = v[high];
            int i = (low - 1);
         
            for (int j = low; j <= high- 1; j++){
                if (v[j] <= pivot){
                    i++;
                    swap(v[i], v[j]);
                }
                contador++;
            }
            swap(v[i + 1], v[high]);
            return (i + 1);
        }

template<class Clave>    
void quick_sort(vector<Clave>& v, int low, int high, int demostrar){
            
            if (low < high){
                int pi = particion(v, low, high);
                if(demostrar==1){
                    write(cout,v);
                    cin.get();
                }
                quick_sort(v, low, pi - 1,demostrar);
                quick_sort(v, pi + 1, high,demostrar);
            }
        }

template<class Clave>    
void shell_sort(vector<Clave>& v, int demostrar){
            
            for (int gap = v.size()/2; gap > 0; gap /= 2){
                for (int i = gap; i < v.size(); i++){
                    
                    int temp = v[i];
                    int j;            
                    for (j = i; j >= gap && v[j - gap] > temp; j -= gap){
                        contador++;
                        v[j] = v[j - gap];
                        if(demostrar==1){
                        write(cout,v);
                        cin.get();
                        }
                    }
                    v[j] = temp;
                }
            }
        }

void set_datos(void){
    
    if(contador<minimo)
        minimo=contador;
    
    if(contador>maximo)
        maximo=contador;
        
    acumulador+=contador;
    contador=0;
}

void write_mmm(int numero_pruebas){
    
    media=(double)acumulador/(double)numero_pruebas;
    
    cout << setw(7) << minimo << "        " << fixed << setprecision(4) << media << "       " << setw(7) << maximo << endl;
    
    minimo=999999999;
    maximo=0;
    media=0;
    acumulador=0;
}