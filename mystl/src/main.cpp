#include "../include/array.h"
#include "../include/stack.h"
#include "../include/ll.h"
#include "../include/queue.h"

int main(void){
    
    std::cout << "VECTOR" << std::endl << std::endl;
    
    vector_<int> vec(20);
    
    for(int i=0;i<20;i++)
        vec[i]=i;
        
    for(int i=0;i<20;i++)
        std::cout << vec[i] << ", ";
    
    std::cout<<std::endl;
        
    vec.resize(25);
    std::cout<<vec.get_sz()<<std::endl;
    
    for(int i=0;i<25;i++)
        std::cout << vec[i] << ", ";
    
    std::cout << std::endl;
    
    vec.destroy_vec();
    
    std::cout << std::endl << "PILA" << std::endl << std::endl;
    
    stack_<int> stack(3);
    
    if(stack.empty())
    std::cout<<"Está vacio"<<std::endl;
    
    stack.push(2);
    stack.push(7);
    
    if(stack.empty())
    std::cout<<"Está vacio"<<std::endl;
    
    std::cout << stack.top() << std::endl;
    
    stack.pop();
    
    std::cout << stack.top() << std::endl;
    
    stack.pop();
    
    std::cout << std::endl << "COLA" << std::endl << std::endl;
    
    cola<int> queue(10);
    if(queue.empty())
    std::cout<<"Está vacio"<<std::endl;
    
    for(int i=0;i<10;i++)
        queue.push(i+1);
    
    if(queue.empty())
    std::cout<<"Está vacio"<<std::endl;
    
    std::cout << std::endl << "Elemento primero de la cola: " << queue.front();
    std::cout << std::endl << "Elemento ultimo de la cola: " << queue.back();
    std::cout << std::endl << "Tamaño de la cola actual: "  << queue.size() <<std::endl;
    
    int a=queue.size();
    for (int i=0;i < a; i++){
        cout << i+1 << ".- " << queue.front() << endl;
        queue.pop();
    }
    std::cout<<std::endl;
    
}