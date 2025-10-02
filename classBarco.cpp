#include "clasebarco.h"
#include <limits>

static int leerEnteroSeguro(const char* prompt) {
    int v;
    while (true) {
        std::cout << prompt;
        if (std::cin >> v) return v;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Entrada inválida. Intenta de nuevo.\n";
    }
}

Barco::Barco() {
    PedirCoordenadas();
}

void Barco::PedirCoordenadas() {
    std::cout << "Ingrese las coordenadas del barco (4 celdas en el rango 0..19):\n";
    for (int i = 0; i < 4; ++i) {
        std::cout << "Posicion " << i << ":\n";
        int x = leerEnteroSeguro("  x: ");
        int y = leerEnteroSeguro("  y: ");
        celdas[i] = {x, y};
    }
    std::cout << std::endl;
}
