#include <cstdlib>
#include <iostream>
#include <vector>

#include "quick.hpp"

int main(void){    

    vector<int> vec(20);
    quick<int> q;
    
    q.set_demos(1);
    
    srand(time(NULL));
    
    for(int j=0;j<vec.size();j++)
        vec[j]=rand()%99999999;
        
    for(int j=0;j<vec.size();j++)
        cout << vec[j] << ", ";
    cout << endl << endl;
    
    q.quick_sort(vec, 0, vec.size()-1);
    
            
    for(int j=0;j<vec.size();j++)
        cout << vec[j] << ", ";
    cout << endl << endl;
    
}