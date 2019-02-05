#include "maquina.hpp"
#include <time.h>
#include <cstdlib>
#include <iostream>

int main(void)
{
	
	char seleccion;
	maquina A;	
	
	cout << "¿Quiere que la rejilla tenga una distribución de colores aleatoria? (y/n): ";
	cin >> seleccion;
	
	if(seleccion=='y'){
		A.aleatorio();
		A.paso();
	}
	else if(seleccion=='n')
		A.paso();
	else
		cerr << "Error de selección, opción no encontrada." << endl;
	
	
}