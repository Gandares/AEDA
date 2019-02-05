#include "../include/AB.hpp"

void ArbolB::podar(nodo* &node){
    
      if (node == NULL) 
        return ;   
      podar(node->get_izq());   
      podar(node->get_dcho());
      delete node;
      node = NULL;
}

bool ArbolB::empty() const{ 
    
    return raiz_==NULL;
}

nodo* ArbolB::raiz(void) const{
    
    return raiz_;
}

nodo*& ArbolB::raiz(void){
    
    return raiz_;
}

nodo* ArbolB::minimo(nodo* t){
        if(t==NULL)
            return NULL;
        else if(t->get_izq()==NULL)
            return t;
        else
            return minimo(t->get_izq());
}

void ArbolB::pornivel(void){
    
    struct pair_t{
        int nivel;
        nodo* node;
    }pair;
    
    struct aux_t{
        int nivel;
        bool null = false;
        dni DNI;
    }aux;
    
    queue<pair_t> q;
    queue<aux_t> p;
    nodo* n;
    int nivel, nivel_actual = 0;

    pair.nivel = 0;     
    pair.node = raiz_;
    q.push(pair);
    
    while(!q.empty()){
        
            n = q.front().node;
            nivel = q.front().nivel;
            q.pop();
            
            if(nivel>nivel_actual)
                nivel_actual = nivel;
            
            if(n==NULL){
                aux.null = true;
                aux.nivel = nivel_actual;
                p.push(aux);
            }
            else{
                aux.DNI = n->get_dato();
                aux.nivel = nivel_actual;
                aux.null = false;
                p.push(aux);
                
                //q.push(n->get_izq()->get_dato(),nivel+1);
                //q.push(n->get_dcho()->get_dato(),nivel+1);
                pair.nivel = nivel + 1;
                pair.node = n->get_izq();
                q.push(pair);
            
                pair.nivel = nivel + 1;
                pair.node = n->get_dcho();
                q.push(pair);
            }
    }
    
    nivel = 0;
    cout << "Nivel[" << nivel << "]: ";
    
        while(!p.empty()){
            if(nivel!=p.front().nivel){
                cout << endl;
                cout << "Nivel[" << p.front().nivel << "]: ";
                nivel = p.front().nivel;
            }
        
            if(p.front().null == false){
                cout << p.front().DNI.get_num() << ", ";
            }
        else{
            cout << "   .   , ";
        }
        p.pop();
        }
}

void ArbolB::insertar(long int n){
    
        dni DNI(n);
        insertar1(raiz_,DNI);
}

void ArbolB::insertar1(nodo* &node, dni key){
    
    if(node==NULL){
        node = new nodo(key);
    }
    if (key.get_num() < node->get_dato())
       insertar1(node->get_izq(),key);
    else if (key.get_num() > node->get_dato())
        insertar1(node->get_dcho(),key);
}

void ArbolB::buscar(nodo* node, long int key, int& cont, bool doe) const{
    
    // Base Cases: root is null or key is present at root
    if (node==NULL){
        cont++;
        if(doe==true)
            cout << "No encontrado." << endl;
    }
    else if(node->get_dato()==key){
        cont++;
        if(doe==true)
        cout << "Encontrado." << endl;
    }
    else if (node->get_dato() < key){
        cont++;
        return buscar(node->get_dcho(), key, cont, doe);
    }
    else if (node->get_dato() > key){
        cont++;
        return buscar(node->get_izq(), key, cont, doe);
    }
}

void ArbolB::eliminar(dni key, nodo* &t){
    
        int x;
        nodo* aux;
        if(t==NULL){}
        
        else if(key.get_num() > t->get_dato())
            eliminar(key, t->get_dcho());
            
        else if(key.get_num() < t->get_dato())
            eliminar(key, t->get_izq());
            
        else if(t->get_izq() && t->get_dcho()){
            aux = minimo(t->get_dcho());
            t->set_dato(aux->get_dato());
            eliminar(t->get_dato(x),t->get_dcho());
        }
        
        else{
            aux=t;
            if(t->get_izq()==NULL)
                t = t->get_dcho();
            else if(t->get_dcho()==NULL)
                t = t->get_izq();
            delete aux;
        }
}