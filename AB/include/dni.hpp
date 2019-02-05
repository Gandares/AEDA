#ifndef dni_hpp
#define dni_hpp
#include <time.h>
#include <cstdlib>

using namespace std;

class dni{
    
private:

    long int num;
    
public:

    dni(){
        
        srand(time(NULL));
        num=rand()%99999999;
        while(num<10000000)
            num=rand()%99999999;
    }
    
    dni(const long int n):
    num(n)
    {}
    
    long int get_num(void){
        
        return num;
    }
    
    void set_num(long int n){
        
        num=n;
    }
};

#endif