#include <iostream>
#include <string>


//===Código de fondo de color===/


#define  BG_RED      "\x1B[41m"
#define  BG_WHITE    "\x1B[47m"
#define  BG_GRAY     "\x1B[48;2;176;174;174m"
#define  BG_BLUE     "\x1B[44m"
#define  RESET       "\x1b[0m"

using namespace std;

string Colors[] = {BG_RED, BG_WHITE, BG_GRAY, BG_BLUE};


//---------//




Casilla::Casilla(){
    
    estado = 3;
    
}

void Casilla::MarcarImpacto(){
    
    estado = 0;
    
}


void Casilla::PonerBarco(){
    
    estado = 2;
    
}


void Casilla::MarcarSinImpacto(){
    
    estado = 1;
    
}

void Casilla::Mar(){
    
    estado = 3;
    
}


void Casilla::Mostrar(bool tipo){
    
    if(tipo){
        
        cout << Colors[estado] << ". " << RESET;
        
    }else{
        
        if(estado == 2){
            
            cout << Colors[3] << ". " << RESET;
            
        }else{
            
            cout << Colors[estado] << ". " << RESET;
            
        }
        
    }
    
}

// -------------------------/// 


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
        
        cout << endl;
    }
    
    cout << endl; 
    cout << endl;
}

void Tablero::PonerBarco(Barco b){
		
    for(int i=0; i<4; i++){
		
		Core[b.coordenadas[0][i]][b.coordenadas[1][i]].PonerBarco();

	}
    
}



int main()
{
    
    Tablero juego(true);
    
    juego.Mostrar();
    
    Barco b;
    
    juego.PonerBarco(b);
    /*
    juego.Core[2][2].PonerBarco();
    juego.Core[3][2].PonerBarco();
    juego.Core[4][2].PonerBarco();
    juego.Core[5][2].PonerBarco();
    
    
    juego.Core[5][9].PonerBarco();
    juego.Core[5][10].PonerBarco();
    juego.Core[5][11].PonerBarco();
    juego.Core[5][12].PonerBarco();
    juego.Core[5][13].PonerBarco();
    */
    
    
    juego.Mostrar();

    return 0;
}
