#include <cstdlib>
#include <iostream>
#include <vector>

#include "heapsort.hpp"

int main(void){    

    vector<int> vec(20);
    heap<int> h;
    
    h.set_demos(1);
    
    srand(time(NULL));
    
    for(int j=0;j<vec.size();j++)
        vec[j]=rand()%99999999;
    
    h.heap_sort(vec);
    
            
    for(int j=0;j<vec.size();j++)
        cout << vec[j] << ", ";
    cout << endl << endl;
    
}