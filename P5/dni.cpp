#include "dni.hpp"
#include <stdlib.h>
#include <time.h>

void dni::rellenar(vector<int>& v){
    
    srand(time(NULL));
    for(int j=0;j<v.size();j++){
        v[j]=rand()%99999999;
        while(v[j]<10000000)
            v[j]=rand()%99999999;
    }    
}

void dni::rellenar_semilla(vector<int>& v, int seed){
    
    srand(seed);
    for(int j=0;j<v.size();j++){
        v[j]=rand()%99999999;
        while(v[j]<10000000)
            v[j]=rand()%99999999;
    }
}

int dni::semilla(void){
    
    srand(time(NULL));
    num=rand()%99999999;
    return num;
}