#include <iostream>
#include <limits>
#include "claseCasilla.h"
#include "clasebarco.h"
#include "classTablero.h"

static int leerOpcion() {
    int op;
    while (true) {
        std::cout << "Opción: ";
        if (std::cin >> op) return op;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Entrada inválida. Intenta de nuevo.\n";
    }
}

int main() {
    std::cout << "==== Batalla Naval (Consola) ====\n";
    Tablero juego(true);

    bool salir = false;
    while (!salir) {
        std::cout
            << "\n--- MENU ---\n"
            << "1) Mostrar tablero\n"
            << "2) Colocar un barco (4 celdas)\n"
            << "3) Guardar partida\n"
            << "4) Cargar partida\n"
            << "5) Cambiar tipo (propio/enemigo)\n"
            << "0) Salir\n";

        int op = leerOpcion();
        switch (op) {
            case 1: {
                juego.Mostrar();
                break;
            }
            case 2: {
                Barco b;
                juego.PonerBarco(b);
                std::cout << "Barco colocado.\n";
                break;
            }
            case 3: {
                std::string ruta;
                std::cout << "Archivo para guardar (ej. partida.txt): ";
                std::cin >> ruta;
                if (juego.GuardarPartida(ruta)) {
                    std::cout << "Partida guardada en '" << ruta << "'.\n";
                } else {
                    std::cout << "No se pudo guardar la partida.\n";
                }
                break;
            }
            case 4: {
                std::string ruta;
                std::cout << "Archivo a cargar (ej. partida.txt): ";
                std::cin >> ruta;
                if (juego.CargarPartida(ruta)) {
                    std::cout << "Partida cargada desde '" << ruta << "'.\n";
                } else {
                    std::cout << "No se pudo cargar la partida.\n";
                }
                break;
            }
            case 5: {
                std::cout << "0 = enemigo (oculta barcos), 1 = propio: ";
                int t = leerOpcion();
                juego.SetTipo(t != 0);
                std::cout << "Tipo actualizado.\n";
                break;
            }
            case 0:
                salir = true;
                break;
            default:
                std::cout << "Opción no válida.\n";
        }
    }

    std::cout << "¡Hasta pronto!\n";
    return 0;
}
