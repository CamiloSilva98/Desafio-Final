#ifndef GESTORARCHIVOS_H
#define GESTORARCHIVOS_H

#include <string>

class GestorArchivos {
public:
    static void guardarEstado(const std::string& archivo, int posicionX, int posicionY, int saludJugador);
    static bool cargarEstado(const std::string& archivo, int& posicionX, int& posicionY, int& saludJugador);
};

#endif // GESTORARCHIVOS_H
