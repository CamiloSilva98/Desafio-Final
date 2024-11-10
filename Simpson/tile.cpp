#include "tile.h"
#include <iostream>

Tile::Tile(int x, int y, TipoTile tipo, const std::string& spritePath)
    : x(x), y(y), tipo(tipo), sprite(spritePath) {}

bool Tile::esCaminable() const {
    return tipo == CAMINABLE;
}

bool Tile::esPuerta() const {
    return tipo == PUERTA;
}
//
void Tile::dibujar() const {
    // Código para dibujar el sprite del tile en pantalla
    std::cout << "Dibujando tile en (" << x << ", " << y << ") con sprite " << sprite << std::endl;
}

int Tile::getX() const { return x; }
int Tile::getY() const { return y; }
