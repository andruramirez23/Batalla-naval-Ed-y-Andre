#pragma once
#include "claseCasilla.h"
#include "clasebarco.h"
#include <string>

class Tablero {
private:
    bool tipo_; // true: propio; false: enemigo

public:
    static constexpr int kAncho = 20;
    static constexpr int kAlto  = 20;

    Casilla Core[kAncho][kAlto];

    explicit Tablero(bool tipoPropio);
    void Mostrar() const;
    void PonerBarco(const Barco& b);

    // === Guardado / Carga de partidas ===
    // Devuelven true si la operación fue exitosa
    bool GuardarPartida(const std::string& ruta) const;
    bool CargarPartida(const std::string& ruta);

    bool EsPropio() const { return tipo_; }
    void SetTipo(bool propio) { tipo_ = propio; }
};
