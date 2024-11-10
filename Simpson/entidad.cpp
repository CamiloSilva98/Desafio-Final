#include "entidad.h"
#include <QPixmap>
#include <iostream>

Entidad::Entidad(int x, int y, const std::string& spritePath)
    : posicionX(x), posicionY(y), sprite(spritePath)
{
    // Cargar el sprite y establecerlo en el QGraphicsPixmapItem
    QPixmap pixmap(QString::fromStdString(sprite));
    setPixmap(pixmap);

    // Posicionar el ítem en la escena
    setPos(x * 16, y * 16);
}

void Entidad::dibujar() const {
    std::cout << "Dibujando entidad en (" << posicionX << ", " << posicionY << ") con sprite " << sprite << std::endl;
    // Ya no es necesario llamar explícitamente a nada aquí, ya que QGraphicsPixmapItem maneja el dibujo automáticamente en la escena
}

// Métodos para obtener y establecer la posición
int Entidad::getPosicionX() const { return posicionX; }
int Entidad::getPosicionY() const { return posicionY; }

void Entidad::setPosicion(int x, int y) {
    posicionX = x;
    posicionY = y;
    setPos(x * 16, y * 16); // Actualizar posición en la escena
}

