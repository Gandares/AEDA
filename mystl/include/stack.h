#ifndef ARRAY_H
#define ARRAY_H

#include "array.h"

template <class T>
	class stack_{

private:

	vector_<T> v_;																//Vector pila
	int      top_;																//Top de la pila

public:

    stack_(int max_sz):															//Constructor
	v_(max_sz),
	top_(-1)
	{}

	~stack_(void)																//Destructor
	{}

	bool empty(void){															//Comprobar si  esta vacio
		return (top_ < 0);
	}

	T top(void){																//Devolver valor del top
        assert(!empty());
		return v_[top_];
	}

	void pop(void){																//Decrementar valor del top
        assert(!empty());			
		
		top_--;
	}

	void push(T dato){															//Aumentar valor del top  e incluir dato
        assert(top_ < v_.get_sz() - 1);

		top_ ++;
		v_[top_] = dato;
	}
};

#endif