#include <cstdlib>
#include <iostream>
#include <vector>

#include "shell.hpp"

int main(void){    

    vector<int> vec(20);
    shell<int> s;
    
    s.set_demos(1);
    
    srand(time(NULL));
    
    for(int j=0;j<vec.size();j++)
        vec[j]=rand()%99999999;
        
    for(int j=0;j<vec.size();j++)
        cout << vec[j] << ", ";
    cout << endl << endl;
    
    s.shell_sort(vec);
    
            
    for(int j=0;j<vec.size();j++)
        cout << vec[j] << ", ";
    cout << endl << endl;
    
}