#ifndef ITEM_H
#define ITEM_H

#include "Entidad.h"
#include <string>

class Item : public Entidad {
private:
    std::string nombre;
    std::string descripcion;
    std::string efecto; // Define el tipo de efecto (ej. "salud", "llave")
    bool esUsado;

public:
    // Constructor
    Item(int x, int y, const std::string& spritePath, const std::string& nombre,
         const std::string& descripcion, const std::string& efecto);

    // Métodos
    void usar();
    std::string getDescripcion() const;
    bool estaUsado() const;
    void marcarComoUsado();

    // Getters
    std::string getNombre() const;
    std::string getEfecto() const;

    // Sobrecarga de métodos de Entidad
    void dibujar() const override;
};

#endif // ITEM_H

