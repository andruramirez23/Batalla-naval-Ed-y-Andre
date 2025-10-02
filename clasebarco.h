#pragma once
#include <array>
#include <utility>
#include <iostream>

class Barco {
public:
    // 4 celdas (x,y)
    std::array<std::pair<int,int>,4> celdas{};

    Barco();                       // pide por std::cin las 4 coordenadas
    void PedirCoordenadas();       // si prefieres pedirlas luego
};
