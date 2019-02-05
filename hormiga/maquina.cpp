#include "maquina.hpp"
#include "hormiga.hpp"
#include "rejilla.hpp"

#include <iomanip>
#include <cstdlib>

void maquina::inicio(void){             //Establece la posicion inicial de la hormiga, el centro de la matriz.
    
    if(mapa.get_m()%2==0)
        fila = mapa.get_m()/2;
    else
        fila = (1+mapa.get_m())/2;
    
    if(mapa.get_n()%2==0)
        columna = mapa.get_n()/2;
    else
        columna = (1+mapa.get_n())/2;

    trans_direccion=1;
    
    if(doblehormiga=='y'){                  //Para la segunda hormiga, dos columnas a la derecha de la principal.
        if(mapa.get_m()%2==0)
            fila2 = mapa.get_m()/2;
        else
            fila2 = (1+mapa.get_m())/2;
        
        if(mapa.get_n()%2==0)
            columna2 = (mapa.get_n()/2)+2;
        else
            columna2 = ((1+mapa.get_n())/2)+2;
    
        trans_direccion2=1;
    }
}

void maquina::aleatorio(void){
	
	srand(time(NULL));
	for(int i=0;i < mapa.get_m();i++){
		for(int j=0;j < mapa.get_n();j++){
		    if(rand()%2==1)
		    	mapa.set_color(i,j,'X');
			else
			    mapa.set_color(i,j,' ');
		}
	}
}

void maquina::paso(void){
    
    cout << "¿Quiere dos hormigas? (y/n): "; 
    cin >> doblehormiga;
    inicio();
    hormiga H(fila,columna,trans_direccion);
    hormiga H2(fila2,columna2,trans_direccion2);        //Si meto el constructor de la segunda hormiga en un if, me pone como no declarado,
                                                        //esta fue mi unica solución.
    pfil = H.get_pos_i()-15;                //son los actualizadores del write.
    ffil = H.get_pos_i()+15;                //Se mueven haciendo que la camara
    pcol = H.get_pos_j()-15;                //siga a la primera hormiga.
    fcol = H.get_pos_j()+15;                //PROBLEMA aun con dos hormigas sigue siempre a la primera, por eso le di lados grandes al cuadrado.
    
    system("clear");
    
    write();
    cout << "Pulse enter para iterar, puede mantener para mas velocidad. ";
    
    cin.get();
    cin.get(); //Utilizo dos porque el cin del main provoca que el primero no pare el programa, esto fue lo mejor que se me ocurrió.
    
    int infinito=0;
    while(infinito==0){
        
    system("clear");
    
    if(mapa.get_color(fila,columna)==' ')               //Cambio de color en la casilla.
        mapa.set_color(fila,columna, 'X');
    else if(mapa.get_color(fila,columna)=='X')
        mapa.set_color(fila,columna, ' ');
        
        H.movimiento(mapa.get_color(fila,columna),trans_direccion,fila,columna);     //Movimiento de la primera hormiga.
        trans_direccion = H.get_direccion();
        fila = H.get_pos_i();
        columna = H.get_pos_j();
        pfil = H.get_pos_i()-15;                        //Actualizadores del write.
        ffil = H.get_pos_i()+15;                        //Si la segunda hormiga sale del rango seguira viva e iterando
        pcol = H.get_pos_j()-15;                        //Si entra en el rango de nueva se volverá a ver.
        fcol = H.get_pos_j()+15;
        
        if(doblehormiga=='y'){
            
        if(mapa.get_color(fila2,columna2)==' ')               //Cambio de color en la casilla de la segunda hormiga.
            mapa.set_color(fila2,columna2, 'X');
        else if(mapa.get_color(fila2,columna2)=='X')
            mapa.set_color(fila2,columna2, ' ');
            
            H2.movimiento(mapa.get_color(fila2,columna2),trans_direccion2,fila2,columna2);
            trans_direccion2 = H2.get_direccion();
            fila2 = H2.get_pos_i();
            columna2 = H2.get_pos_j();
        }
        
        write();
        cout << "Pulse enter para iterar, puede mantener para mas velocidad. ";
        
        cin.get();
    }
}

ostream& maquina::write(void){

	for(int i=pfil;i <= ffil;i++){
		cout << i << "|";
		for(int j=pcol;j <= fcol;j++){
			if(i==fila&&j==columna){                                   //Impresión de la primera hormiga.
        		if(trans_direccion==1)
        			cout << setw(3) << "^";
        		if(trans_direccion==2)
        			cout << setw(3) << ">";
    			if(trans_direccion==3)
    				cout << setw(3) << "v";
        		if(trans_direccion==4)
        			cout << setw(3) << "<";
			}
			if(doblehormiga=='y'){                                    //Impresión de la segunda hormiga con su dirección.
			    if((i==fila&&j==columna)&&(i==fila2&&j==columna2)){}  //No se imprimira la segunda hormiga si las dos coinciden.
			    else{
    				if(i==fila2&&j==columna2){       
            			if(trans_direccion2==1)     
            				cout << setw(3) << "^";
            			if(trans_direccion2==2)
        					cout << setw(3) << ">";
        				if(trans_direccion2==3)
        					cout << setw(3) << "v";
        				if(trans_direccion2==4)
        					cout << setw(3) << "<";
        			}
        		}
			}
			if(!((i==fila&&j==columna)||(i==fila2&&j==columna2)))
			    cout << setw(3) << mapa.get_color(i,j);
		}
		cout << " |";
		cout << endl;
	}
	cout << endl;
}