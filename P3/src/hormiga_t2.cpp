#include "../include/hormiga_t2.hpp"

hormiga_t2::hormiga_t2(int f, int c):
hormiga(f,c)
{}

void hormiga_t2::movimiento(char color){
    
    switch(color){
        case ' ':
            direccion++;
            if(direccion==5)
                direccion=1;
            break;
        case 'X':
            direccion--;
            if(direccion==0)
                direccion=4;
            break;
        case 'R':
            direccion++;
            if(direccion==5)
                direccion=1;
            break;
        case 'A':
            direccion++;
            if(direccion==5)
                direccion=1;
            break;
        default:
            cerr << "Error al cambiar el color." << endl;
            exit;
    }
        
    switch(direccion){
            
        case 1:                                                                 //^
            posicioni--;
            break;
        case 2:                                                                 //>
            posicionj++;
            break;
        case 3:                                                                 //v
            posicioni++;
            break;
        case 4:                                                                 //<
            posicionj--;
            break;
        default:
            cerr << "Error en la dirección." << endl;
            exit;
    }
}

ostream& hormiga_t2::write(void){

    if(direccion==1)
    	cout << setw(3) << "^2";
	else if(direccion==2)
		cout << setw(3) << ">2";
    else if(direccion==3)
		cout << setw(3) << "v2";
	else if(direccion==4)
		cout << setw(3) << "<2";
}