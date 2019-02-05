#include <cstdlib>
#include <iostream>
#include <vector>

#include "bubble.hpp"

int main(void){    


    vector<int> vec(20);
    bubble<int> bb;
    
    bb.set_demos(1);
    
    srand(time(NULL));
    
    for(int j=0;j<vec.size()+1;j++)
        vec[j]=rand()%99999999;
    
    bb.bubble_sort(vec);
    
}