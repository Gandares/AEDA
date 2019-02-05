#include "../include/array.h"

int main(void){
    
    vector_<int> vector1(10);
    
    for(int i=0;i<vector1.get_sz();i++)
        vector1[i]=i+1;
    
    std::cout << "Vector 1: ";
    
    for(int i=0;i<vector1.get_sz();i++)
        std::cout << vector1[i] << " ,";
        
    vector_<int> vector2(vector1);
    
    std::cout << std::endl << "Vector 2: ";
    
    for(int i=0;i<vector2.get_sz();i++)
        std::cout << vector2[i] << " ,";
    
    std::cout << std::endl;
}