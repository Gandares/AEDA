#include "../include/AVL.hpp"


void ArbolAVL::insertar(dni DNI){
    
    nodo* n = new nodo(DNI,0);
    bool crece = false;
    i_bal(ArbolB::raiz_, n, crece);
}

void ArbolAVL::sustituye(nodo* &eliminado, nodo* &sustituto, bool &decrece){
    
    if(sustituto->get_dcho()!=NULL){
        sustituye(eliminado, sustituto->get_dcho(), decrece);
        if(decrece)
            e_balancea_dcha(sustituto, decrece);
    }
    else{
        eliminado->set_dato(sustituto->get_dato());
        eliminado = sustituto;
        sustituto = sustituto->get_izq();
        decrece = true;
    }
}

void ArbolAVL::eliminar(long int num){
    
    dni DNI(num);
    bool decrece = false;
    eliminar_rama(ArbolB::raiz_,DNI,decrece);
}

void ArbolAVL::i_bal(nodo* &n1, nodo* n2, bool& crece){
    
    if(n1 == NULL){
        n1 = n2;
        crece = true;
    }
    else if(n2->get_dato() < n1->get_dato()){
        i_bal(n1->get_izq(), n2, crece);
        if(crece)
            i_balancea_izq(n1,crece);
    }
    else{
        i_bal(n1->get_dcho(), n2, crece);
        if(crece)
            i_balancea_dcha(n1,crece);
    }
}

void ArbolAVL::i_balancea_izq(nodo* &n, bool& crece){
    
    switch(n->get_balance()){
            
        case -1:
            n->set_balance(0);
            crece = false;
            break;
            
        case 0:
            n->set_balance(1);
            break;

        case 1:
            nodo* aux = n->get_izq();
            if(aux->get_balance() == 1)
                rotar_II(n);
            else
                rotar_ID(n);
            crece = false;
    }
}

void ArbolAVL::i_balancea_dcha(nodo* &n, bool& crece){
    
    switch(n->get_balance()){
        
        case 1:
            n->set_balance(0);
            crece = false;
            break;
        case 0:
            n->set_balance(-1);
            break;

        case -1:
            nodo* aux = n->get_dcho();
            if(aux->get_balance() == -1)
                rotar_DD(n);
            else
                rotar_DI(n);
            crece = false;
    }
}

void ArbolAVL::eliminar_rama(nodo* &r, dni DNI, bool& decrece){
    
    if(r == NULL){}
        
    if(DNI.get_num() < r->get_dato()){ 
        eliminar_rama(r->get_izq(),DNI,decrece);
        if(decrece)
            e_balancea_izq(r,decrece);
    }
    else if(DNI.get_num() > r->get_dato()){
        eliminar_rama(r->get_dcho(),DNI,decrece);
        if(decrece)
            e_balancea_dcha(r,decrece);
    }   
    else{
        nodo* temp = r;
        if(r->get_izq()==NULL){
            r = r->get_dcho();
            decrece=true;
        }
        else if(r->get_dcho()==NULL){
            r = r->get_izq();
            decrece= true;
        }
        else{
            sustituye(temp,r->get_izq(),decrece);
            if(decrece)
                e_balancea_izq(r,decrece);
        }
        delete temp;
    }
}

void ArbolAVL::e_balancea_izq(nodo* &n, bool& decrece){
    
    nodo* aux = n->get_dcho();
        
    switch(n->get_balance()){
            
        case -1:
            if(aux->get_balance() > 0)
                rotar_DI(n);
            else{
                if(aux->get_balance() == 0)
                    decrece = false;
                rotar_DD(n);
            }
            break;
        case 0:
            n->set_balance(-1);
            decrece = false;
            break;
        case 1:
            n->set_balance(0);
            break;
    }
}

void ArbolAVL::e_balancea_dcha(nodo* &n, bool& decrece){
    
    switch(n->get_balance()){
        
        case 1:{
            nodo* aux = n->get_izq();
            if(aux->get_balance() < 0)
                rotar_ID(n);
            else{
                if(aux->get_balance() == 0)
                    decrece = false;
                rotar_II(n);
            }
        break;
        }
        case 0:{
            n->set_balance(1);
            decrece = false;
            break;
        }
        case -1:
            n->set_balance(0);
    }
}

void ArbolAVL::rotar_II(nodo* &n){
    
    nodo* temp = n->get_izq();
    n->get_izq() = temp->get_dcho();
    temp->get_dcho() = n;

    if(temp->get_balance() == 1){
        n->set_balance(0);
        temp->set_balance(0);
    }
    else{
        n->set_balance(1);
        temp->set_balance(-1);
    }
    n = temp;
}

void ArbolAVL::rotar_DD(nodo* &n){
    
    nodo* temp = n->get_dcho();
    n->get_dcho() = temp->get_izq();
    temp->get_izq() = n;

    if(temp->get_balance() == -1){
        n->set_balance(0);
        temp->set_balance(0);
    }
    else{
        n->set_balance(-1);
        temp->set_balance(1);
    }
    n = temp;
}

void ArbolAVL::rotar_ID(nodo* &n){
    
    nodo* temp1 = n->get_izq();
    nodo* temp2 = temp1->get_dcho();

    n->get_izq() = temp2->get_dcho();
    temp2->get_dcho() = n;

    temp1->get_dcho() = temp2->get_izq();
    temp2->get_izq() = temp1;

    if(temp2->get_balance() == -1)
        temp1->set_balance(1);
    else
        temp1->set_balance(0);

    if(temp2->get_balance() == 1)
        n->set_balance(-1);
    else
        n->set_balance(0);

    temp2->set_balance(0);
    n = temp2;
}
    
void ArbolAVL::rotar_DI(nodo* &n){
    
    nodo* temp1 = n->get_dcho();
    nodo* temp2 = temp1->get_izq();

    n->get_dcho() = temp2->get_izq();
    temp2->get_izq() = n;
    temp1->get_izq() = temp2->get_dcho();
    temp2->get_dcho() = temp1;

    if(temp2->get_balance() == 1)
        temp1->set_balance(-1);
    else
        temp1->set_balance(0);

    if(temp2->get_balance() == -1)
        n->set_balance(1);
    else
        n->set_balance(0);

    temp2->set_balance(0);
    n = temp2;
}