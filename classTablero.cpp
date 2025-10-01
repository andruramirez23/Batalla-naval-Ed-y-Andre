#include "classTablero.h"
#include <iostream>



Tablero::Tablero(bool tipo_){
    
    tipo = tipo_;
    
    for(int i=0; i<20; i++){
        for(int j=0; j<20; j++){
            
            Core[i][j].Mar();
            
        }
    }
        
}


void Tablero::Mostrar(){
    
    for(int i=0; i<20; i++){
        
        for(int j=0; j<20; j++){
            
            Core[j][i].Mostrar(tipo);
            
        }
        
        std::cout << std::endl;
    }
    
    std::cout << std::endl; 
    std::cout << std::endl;
}

void Tablero::PonerBarco(Barco b){
		
    for(int i=0; i<4; i++){
		
		Core[b.coordenadas[0][i]][b.coordenadas[1][i]].PonerBarco();

	}
    
}

