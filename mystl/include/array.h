#ifndef ARRAY_H
#define ARRAY_H

#include <cstdio>
#include <iostream>
#include <iomanip>

#include <cassert>

template <class T>
    class vector_{
   
private:
    
    T*  v_;                                                                     //Vector
    int sz_;                                                                    //Tamaño
    
public:
    
    vector_(void):                                                              //Constructores
    v_(NULL),
    sz_(0)
    {}
    
    vector_(int sz):
    v_(NULL),
    sz_(sz)
    {
    create_vec();
    }
    
    vector_(const vector_& copia){
    this->v_=copia.v_;
    this->sz_=copia.sz_;
    }
    
    ~vector_(){                                                                 //Destructor
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
    
    T& operator[](int pos){
    	return v_[pos];
    }
    
    T& operator[](int pos) const{
    	return v_[pos];
    }
    
	private:
	
	void create_vec(void){                                                      //Creacion del vector (Usado  en constructores)
        v_ = new T[sz_];
    }
};

#endif