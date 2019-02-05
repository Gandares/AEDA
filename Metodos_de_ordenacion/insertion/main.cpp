#include <cstdlib>
#include <iostream>
#include <vector>

#include "insertion.hpp"

int main(void){
    
    vector<int> vec(20);
    insertion<int> ins;
    
    ins.set_demos(1);
    
    srand(time(NULL));
    
    for(int j=0;j<vec.size();j++)
        vec[j]=rand()%99999999;
    
    ins.insertion_sort(vec);

}