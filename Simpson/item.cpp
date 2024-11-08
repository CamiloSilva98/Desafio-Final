#include "item.h"
#include <iostream>

// Constructor
Item::Item(int x, int y, const std::string& spritePath, const std::string& nombre,
           const std::string& descripcion, const std::string& efecto)
    : Entidad(x, y, spritePath), nombre(nombre), descripcion(descripcion), efecto(efecto), esUsado(false) {}

// Método para usar el ítem
void Item::usar() {
    if (!esUsado) {
        std::cout << "Usando el ítem: " << nombre << " - " << descripcion << std::endl;
        // Aplica el efecto según el tipo de ítem
        if (efecto == "salud") {
            std::cout << "La salud del jugador ha sido restaurada." << std::endl;
        } else if (efecto == "llave") {
            std::cout << "Se ha usado una llave para desbloquear una puerta." << std::endl;
        }
        esUsado = true; // Marcar el ítem como usado
    } else {
        std::cout << "El ítem " << nombre << " ya fue utilizado y no se puede usar de nuevo." << std::endl;
    }
}

// Obtener la descripción del ítem
std::string Item::getDescripcion() const {
    return descripcion;
}

// Verificar si el ítem ya ha sido usado
bool Item::estaUsado() const {
    return esUsado;
}

// Marcar el ítem como usado
void Item::marcarComoUsado() {
    esUsado = true;
}

// Obtener el nombre del ítem
std::string Item::getNombre() const {
    return nombre;
}

// Obtener el efecto del ítem
std::string Item::getEfecto() const {
    return efecto;
}

// Sobrecarga del método dibujar() para mostrar el ítem en pantalla
void Item::dibujar() const {
    Entidad::dibujar();
    std::cout << "Dibujando ítem: " << nombre << " en posición (" << posicionX << ", " << posicionY << ")" << std::endl;
}
