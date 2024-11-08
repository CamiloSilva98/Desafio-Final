#ifndef ENTIDAD_H
#define ENTIDAD_H

#include <string>

class Entidad {
protected:
    int posicionX;
    int posicionY;
    std::string sprite;

public:
    Entidad(int x, int y, const std::string& spritePath);

    virtual void mover() = 0; // Método virtual puro para el movimiento
    virtual void dibujar() const;

    int getPosicionX() const;
    int getPosicionY() const;
    void setPosicion(int x, int y);
};

#endif // ENTIDAD_H

