#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cassert>

#include "round_vector.h"

template <class T>
    class cola{

private:
    
    round_vector<T>           v_;
    int                     front_;
    int                     back_;

public:

    cola(int max_sz):
    v_(max_sz), 
    front_(0), 
    back_(-1) 
    {}
    
    cola(void): 
    v_(NULL), 
    front_(0), 
    back_(-1) 
    {}
    
    ~cola(void){}
    
    bool empty(void){ 
        return (back_ < front_);
    }
    
    int size(void){ 
        return back_ - front_ + 1;
    }
    
    void push(T dato){ 
        assert(size() < v_.get_sz());
    
    back_++;
    v_.get_set_v(back_) = dato;
    }

    void pop(void){ 
        assert(!empty());
    
    front_++;
    }
    
    T front(void){
        assert(!empty());
    
    return v_.get_v(front_);
    }
    
    T back(void){ 
        assert(!empty());

    return v_.get_v(back_);
    }
};

