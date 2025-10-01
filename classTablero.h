<<<<<<< HEAD:class Tablero.cpp
#include <iostream>
#include <string>

=======
#pragma once
#include "claseCasilla.h"
#include "clasebarco.h"
#include <iostream>
>>>>>>> main:classTablero.h

class Tablero{
    
    private:
    
        bool tipo;
    
    public:
        
        Casilla Core[20][20];
        Tablero(bool tipo_);
        void Mostrar();
        void PonerBarco(Barco b);
    
    
};