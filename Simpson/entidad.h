#ifndef ENTIDAD_H
#define ENTIDAD_H

#include <QGraphicsPixmapItem>
#include <string>

class Entidad : public QGraphicsPixmapItem, public QObject
{
protected:
    int posicionX;
    int posicionY;
    std::string sprite; // Ruta de la imagen

public:
    // Constructor
    Entidad(int x, int y, const std::string& spritePath);

    // Métodos de posición
    int getPosicionX() const;
    int getPosicionY() const;
    void setPosicion(int x, int y);

    // Método para dibujar el sprite en la escena
    virtual void dibujar() const;
};

#endif // ENTIDAD_H


