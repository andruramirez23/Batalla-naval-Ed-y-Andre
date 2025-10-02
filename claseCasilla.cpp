#include "claseCasilla.h"
#include <array>

// === Códigos ANSI (solo usados para salida en consola) ===
#define  BG_RED      "\x1B[41m"
#define  BG_WHITE    "\x1B[47m"
#define  BG_GRAY     "\x1B[48;2;176;174;174m"
#define  BG_BLUE     "\x1B[44m"
#define  RESET       "\x1b[0m"

static const std::array<const char*,4> Colors = { BG_RED, BG_WHITE, BG_GRAY, BG_BLUE };

Casilla::Casilla() : estado_(Estado::Mar) {}

void Casilla::MarcarImpacto()    { estado_ = Estado::Impacto; }
void Casilla::PonerBarco()       { estado_ = Estado::Barco; }
void Casilla::MarcarSinImpacto() { estado_ = Estado::SinImpacto; }
void Casilla::Mar()              { estado_ = Estado::Mar; }

void Casilla::Mostrar(bool propio) const {
    int e = ToInt(); // 0..3
    if (!propio) {
        // En tablero enemigo, un barco debe verse como mar
        if (estado_ == Estado::Barco) e = static_cast<int>(Estado::Mar);
    }
    std::cout << Colors[e] << ". " << RESET;
}

int Casilla::ToInt() const {
    return static_cast<int>(estado_);
}

void Casilla::FromInt(int v) {
    if (v < 0) v = 0;
    if (v > 3) v = 3;
    estado_ = static_cast<Estado>(v);
}
