#pragma once
#include <iostream>

enum class Estado : int {
    Impacto = 0,      // Rojo
    SinImpacto = 1,   // Blanco
    Barco = 2,        // Gris
    Mar = 3           // Azul (vacío)
};

class Casilla {
private:
    Estado estado_; // default: Mar

public:
    Casilla();

    // Acciones de juego
    void MarcarImpacto();
    void PonerBarco();
    void MarcarSinImpacto();
    void Mar();

    // Renderizado (true = tablero propio; false = tablero enemigo)
    void Mostrar(bool propio) const;

    // Soporte guardado/carga
    int  ToInt() const;       // 0..3
    void FromInt(int v);      // 0..3
    Estado Get() const { return estado_; }
};
