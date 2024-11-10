#ifndef TILE_H
#define TILE_H

#include <string>

enum TipoTile {
    CAMINABLE,
    MURO,
    PUERTA
};

class Tile {
private:
    int x, y;
    TipoTile tipo;
    std::string sprite;

public:
    Tile(int x, int y, TipoTile tipo, const std::string& spritePath);

    bool esCaminable() const;
    bool esPuerta() const;
    void dibujar() const;

    // Getters de posición
    int getX() const;
    int getY() const;
};

#endif // TILE_H

