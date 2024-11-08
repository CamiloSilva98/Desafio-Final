#include "entidad.h"
#include <iostream>

Entidad::Entidad(int x, int y, const std::string& spritePath)
    : posicionX(x), posicionY(y), sprite(spritePath) {}

void Entidad::dibujar() const {
    // Aquí iría el código para dibujar el sprite en pantalla
    std::cout << "Dibujando entidad en (" << posicionX << ", " << posicionY << ") con sprite " << sprite << std::endl;
}

int Entidad::getPosicionX() const { return posicionX; }
int Entidad::getPosicionY() const { return posicionY; }

void Entidad::setPosicion(int x, int y) {
    posicionX = x;
    posicionY = y;
}
