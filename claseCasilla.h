#pragma once
#include <iostream>
#include <string>

class Casilla{
    
    private:
    /*
        estado
         0:I: Impacto.  Rojo
         1:N: Sin impacto. Blanco
         2:B: Barco. Gris
         3:M: Mar (Vacio). Azul
    */
        int estado;
    
    public:
    
        
        Casilla();
        void MarcarImpacto();
        void PonerBarco();
        void MarcarSinImpacto();
        void Mar();
        void Mostrar(bool tipo); // True: tablero propio. False: tablero enemigo.
        
};