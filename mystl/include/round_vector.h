#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cassert>

template <class T>
    class round_vector{
        
private:
    
    T*  v_;                                                                     //Vector
    int sz_;                                                                    //Tamaño
 
public:
    
    round_vector(void):                                                              //Constructores
    v_(NULL),
    sz_(0)
    {}
    
    round_vector(int sz):
    v_(NULL),
    sz_(sz)
    {
    create_vec();
    }
    
    ~round_vector(){                                                                 //Destructor
    destroy_vec();
    }
    
    void destroy_vec(void){                                                     //Destruccion del vector (Usado en destructor)
        if(v_!=NULL){
            delete [] v_;
            v_ = NULL;
        }
    }
    
    void resize(int sz){                                                        //Redimensionar vector
        destroy_vec();
        sz_=sz;
        create_vec();
    }
    
    int get_sz(void){                                                           //devolver tamaño
        return sz_;
    }
    
    T get_v(int pos) const{ 
        return v_[pos % sz_]; 
    }

    T& get_set_v(int pos){ 
        return v_[pos % sz_]; 
    }
	
	private:
	
	void create_vec(void){                                                      //Creacion del vector (Usado  en constructores)
        v_ = new T[sz_];
    }
};
