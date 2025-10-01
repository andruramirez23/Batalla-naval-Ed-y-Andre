#include "clasebarco.h"

 Barco::Barco(){
	
	std::cout << "Ingrese las coordenadas del barco" << std::endl;
	
	for(int i=0; i<4; i++){
		
		std::cout << "Posicion " << i << ": "<<std::endl;
		std::cout << " x: ";
		std::cin >> coordenadas[0][i];
		std::cout << " y: ";
		std::cin >> coordenadas[1][i];
		std::cout << std::endl;
	
	}
	
}