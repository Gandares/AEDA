#include "../include/maquina.hpp"
#include "../include/hormiga.hpp"
#include "../include/hormiga_t1.hpp"
#include "../include/hormiga_t2.hpp"
#include "../include/hormiga_t3.hpp"
#include "../include/hormiga_t4.hpp"
#include "../include/hormiga_t5.hpp"
#include "../include/rejilla.hpp"

#include <iomanip>
#include <cstdlib>

void maquina::aleatorio(void){
	
	srand(time(NULL));
	for(int i=0;i < mapa.get_m();i++){
		for(int j=0;j < mapa.get_n();j++){
		    if(rand()%4==0)
		    	mapa.set_color(i,j,' ');
			else if(rand()%4==1)
			    mapa.set_color(i,j,'X');
			else if(rand()%4==2)
		    	mapa.set_color(i,j,'R');
			else if(rand()%4==3)
			    mapa.set_color(i,j,'A');
		}
	}
}

void maquina::paso(void){
    
    hormiga_t1 H1(250,250);
    hormiga_t2 H2(250,253);
    hormiga_t3 H3(253,250);
    hormiga_t4 H4(247,250);
    hormiga_t5 H5(250,247);

    pfil = H1.get_pos_i()-15;                //son los actualizadores del write.
    ffil = H1.get_pos_i()+15;                //Se mueven haciendo que la camara
    pcol = H1.get_pos_j()-15;                //siga a la primera hormiga.
    fcol = H1.get_pos_j()+15;                //PROBLEMA aun con dos hormigas sigue siempre a la primera, por eso le di lados grandes al cuadrado.
    
    system("clear");
    
    write(H1,H2,H3,H4,H5);
    cout << "Colores    XRA" << endl;
    cout << "Hormiga 1 IDID" << endl;
    cout << "Hormiga 2 IDDD" << endl;
    cout << "Hormiga 3 DIDI" << endl;
    cout << "Hormiga 4 IIDI" << endl;
    cout << "Hormiga 5 DIDD" << endl;
    cout << "Pulse enter para iterar, puede mantener para mas velocidad. ";
    
    cin.get();
    cin.get(); //Utilizo dos porque el cin del main provoca que el primero no pare el programa, esto fue lo mejor que se me ocurrió.
    
    int infinito=0;
    while(infinito==0){

    system("clear");
    
    if(mapa.get_color(H1.get_pos_i(),H1.get_pos_j())==' ')
        mapa.set_color(H1.get_pos_i(),H1.get_pos_j(), 'X');
    else if(mapa.get_color(H1.get_pos_i(),H1.get_pos_j())=='X')
        mapa.set_color(H1.get_pos_i(),H1.get_pos_j(), 'R');
    else if(mapa.get_color(H1.get_pos_i(),H1.get_pos_j())=='R')
        mapa.set_color(H1.get_pos_i(),H1.get_pos_j(), 'A');
    else if(mapa.get_color(H1.get_pos_i(),H1.get_pos_j())=='A')
        mapa.set_color(H1.get_pos_i(),H1.get_pos_j(), ' ');
        
        H1.movimiento(mapa.get_color(H1.get_pos_i(),H1.get_pos_j()));
        
        
    if(mapa.get_color(H2.get_pos_i(),H2.get_pos_j())==' ')
        mapa.set_color(H2.get_pos_i(),H2.get_pos_j(), 'X');
    else if(mapa.get_color(H2.get_pos_i(),H2.get_pos_j())=='X')
        mapa.set_color(H2.get_pos_i(),H2.get_pos_j(), 'R');
    else if(mapa.get_color(H2.get_pos_i(),H2.get_pos_j())=='R')
        mapa.set_color(H2.get_pos_i(),H2.get_pos_j(), 'A');
    else if(mapa.get_color(H2.get_pos_i(),H2.get_pos_j())=='A')
        mapa.set_color(H2.get_pos_i(),H2.get_pos_j(), ' ');
        
        H2.movimiento(mapa.get_color(H2.get_pos_i(),H2.get_pos_j()));
        
            
    if(mapa.get_color(H3.get_pos_i(),H3.get_pos_j())==' ')
        mapa.set_color(H3.get_pos_i(),H3.get_pos_j(), 'X');
    else if(mapa.get_color(H3.get_pos_i(),H3.get_pos_j())=='X')
        mapa.set_color(H3.get_pos_i(),H3.get_pos_j(), 'R');
    else if(mapa.get_color(H3.get_pos_i(),H3.get_pos_j())=='R')
        mapa.set_color(H3.get_pos_i(),H3.get_pos_j(), 'A');
    else if(mapa.get_color(H3.get_pos_i(),H3.get_pos_j())=='A')
        mapa.set_color(H3.get_pos_i(),H3.get_pos_j(), ' ');
        
        H3.movimiento(mapa.get_color(H3.get_pos_i(),H3.get_pos_j()));
        
    
    if(mapa.get_color(H4.get_pos_i(),H4.get_pos_j())==' ')
        mapa.set_color(H4.get_pos_i(),H4.get_pos_j(), 'X');
    else if(mapa.get_color(H4.get_pos_i(),H4.get_pos_j())=='X')
        mapa.set_color(H4.get_pos_i(),H4.get_pos_j(), 'R');
    else if(mapa.get_color(H4.get_pos_i(),H4.get_pos_j())=='R')
        mapa.set_color(H4.get_pos_i(),H4.get_pos_j(), 'A');
    else if(mapa.get_color(H4.get_pos_i(),H4.get_pos_j())=='A')
        mapa.set_color(H4.get_pos_i(),H4.get_pos_j(), ' ');
        
        H4.movimiento(mapa.get_color(H4.get_pos_i(),H4.get_pos_j()));
        
        
    if(mapa.get_color(H5.get_pos_i(),H5.get_pos_j())==' ')
        mapa.set_color(H5.get_pos_i(),H5.get_pos_j(), 'X');
    else if(mapa.get_color(H5.get_pos_i(),H5.get_pos_j())=='X')
        mapa.set_color(H5.get_pos_i(),H5.get_pos_j(), 'R');
    else if(mapa.get_color(H5.get_pos_i(),H5.get_pos_j())=='R')
        mapa.set_color(H5.get_pos_i(),H5.get_pos_j(), 'A');
    else if(mapa.get_color(H5.get_pos_i(),H5.get_pos_j())=='A')
        mapa.set_color(H5.get_pos_i(),H5.get_pos_j(), ' ');
        
        H5.movimiento(mapa.get_color(H5.get_pos_i(),H5.get_pos_j()));

        pfil = H1.get_pos_i()-15;                        //Actualizadores del write.
        ffil = H1.get_pos_i()+15;                        //Si la segunda hormiga sale del rango seguira viva e iterando
        pcol = H1.get_pos_j()-15;                        //Si entra en el rango de nueva se volverá a ver.
        fcol = H1.get_pos_j()+15;
        
        write(H1,H2,H3,H4,H5);
        cout << "Colores    XRA" << endl;
        cout << "Hormiga 1 IDID" << endl;
        cout << "Hormiga 2 IDDD" << endl;
        cout << "Hormiga 3 DIDI" << endl;
        cout << "Hormiga 4 IIDI" << endl;
        cout << "Hormiga 5 DIDD" << endl;
        cout << "Pulse enter para iterar, puede mantener para mas velocidad. ";
        
        cin.get();
    }
}

ostream& maquina::write(hormiga_t1 Hor1, hormiga_t2 Hor2, hormiga_t3 Hor3, hormiga_t4 Hor4, hormiga_t5 Hor5){

	for(int i=pfil;i <= ffil;i++){
		cout << i << "|";
		for(int j=pcol;j <= fcol;j++){
			if(i==Hor1.get_pos_i()&&j==Hor1.get_pos_j())
                Hor1.write();
            else if(i==Hor2.get_pos_i()&&j==Hor2.get_pos_j())
                Hor2.write();
            else if(i==Hor3.get_pos_i()&&j==Hor3.get_pos_j())
                Hor3.write();
            else if(i==Hor4.get_pos_i()&&j==Hor4.get_pos_j())
                Hor4.write();
            else if(i==Hor5.get_pos_i()&&j==Hor5.get_pos_j())
                Hor5.write();
			else if(!((i==Hor1.get_pos_i()&&j==Hor1.get_pos_j())||(i==Hor2.get_pos_i()&&j==Hor2.get_pos_j())||(i==Hor3.get_pos_i()&&j==Hor3.get_pos_j())||(i==Hor4.get_pos_i()&&j==Hor4.get_pos_j())||(i==Hor5.get_pos_i()&&j==Hor5.get_pos_j())))
			    cout << setw(3) << mapa.get_color(i,j);
		}
		cout << " |";
		cout << endl;
	}
	cout << endl;
}