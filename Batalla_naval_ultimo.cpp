#include <iostream>
#include <string>
#include "clasebarco.h"
#include "classTablero.h"
#include "claseCasilla.h"

using namespace std;

int main()
{
    
    Tablero juego(true);
    
    juego.Mostrar();
    
    Barco b;
    
    juego.PonerBarco(b);
    
    juego.Core[2][2].PonerBarco();
    juego.Core[3][2].PonerBarco();
    juego.Core[4][2].PonerBarco();
    juego.Core[5][2].PonerBarco();
    
    
    juego.Core[5][9].PonerBarco();
    juego.Core[5][10].PonerBarco();
    juego.Core[5][11].PonerBarco();
    juego.Core[5][12].PonerBarco();
    juego.Core[5][13].PonerBarco();
    
    
    
    juego.Mostrar();

    return 0;
}