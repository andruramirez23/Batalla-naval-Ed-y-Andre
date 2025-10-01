#include <iostream>
#include <string>


class Tablero{
    
    private:
    
        bool tipo;
    
    public:
        
        Casilla Core[20][20];
        Tablero(bool tipo_);
        void Mostrar();
        void PonerBarco(Barco b);
    
    
};