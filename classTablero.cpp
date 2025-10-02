#include "classTablero.h"
#include <fstream>
#include <iostream>
#include <sstream>

Tablero::Tablero(bool tipoPropio) : tipo_(tipoPropio) {
    for (int x = 0; x < kAncho; ++x) {
        for (int y = 0; y < kAlto; ++y) {
            Core[x][y].Mar();
        }
    }
}

void Tablero::Mostrar() const {
    for (int y = 0; y < kAlto; ++y) {
        for (int x = 0; x < kAncho; ++x) {
            Core[x][y].Mostrar(tipo_);
        }
        std::cout << "\n";
    }
    std::cout << "\n\n";
}

void Tablero::PonerBarco(const Barco& b) {
    for (int i = 0; i < 4; ++i) {
        int x = b.celdas[i].first;
        int y = b.celdas[i].second;
        if (x >= 0 && x < kAncho && y >= 0 && y < kAlto) {
            Core[x][y].PonerBarco();
        } else {
            std::cerr << "Coordenada fuera de rango: (" << x << "," << y << ")\n";
        }
    }
}

// === Persistencia simple de tablero ===
// Formato:
// BNV1
// <tipo 0/1>
// <20 líneas, cada una con 20 enteros (0..3) separados por espacio>
bool Tablero::GuardarPartida(const std::string& ruta) const {
    std::ofstream out(ruta, std::ios::out | std::ios::trunc);
    if (!out.is_open()) {
        std::cerr << "No se pudo abrir para escritura: " << ruta << "\n";
        return false;
    }
    out << "BNV1\n";
    out << (tipo_ ? 1 : 0) << "\n";
    for (int y = 0; y < kAlto; ++y) {
        for (int x = 0; x < kAncho; ++x) {
            out << Core[x][y].ToInt();
            if (x + 1 < kAncho) out << ' ';
        }
        out << "\n";
    }
    return true;
}

bool Tablero::CargarPartida(const std::string& ruta) {
    std::ifstream in(ruta);
    if (!in.is_open()) {
        std::cerr << "No se pudo abrir para lectura: " << ruta << "\n";
        return false;
    }
    std::string magic;
    if (!(in >> magic) || magic != "BNV1") {
        std::cerr << "Archivo inválido o corrupto (magic).\n";
        return false;
    }
    int tipoInt = 1;
    if (!(in >> tipoInt)) {
        std::cerr << "Archivo inválido (tipo).\n";
        return false;
    }
    tipo_ = (tipoInt != 0);

    for (int y = 0; y < kAlto; ++y) {
        for (int x = 0; x < kAncho; ++x) {
            int v = 3;
            if (!(in >> v)) {
                std::cerr << "Archivo inválido (datos insuficientes en fila " << y << ").\n";
                return false;
            }
            Core[x][y].FromInt(v);
        }
    }
    return true;
}
