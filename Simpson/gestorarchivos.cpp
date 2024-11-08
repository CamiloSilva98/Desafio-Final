#include "gestorarchivos.h"
#include <fstream>
#include <iostream>

void GestorArchivos::guardarEstado(const std::string& archivo, int posicionX, int posicionY, int saludJugador) {
    std::ofstream archivoSalida(archivo);
    if (archivoSalida.is_open()) {
        archivoSalida << posicionX << " " << posicionY << " " << saludJugador << std::endl;
        archivoSalida.close();
        std::cout << "Estado del juego guardado en " << archivo << std::endl;
    } else {
        std::cerr << "Error al abrir el archivo para guardar el estado." << std::endl;
    }
}

bool GestorArchivos::cargarEstado(const std::string& archivo, int& posicionX, int& posicionY, int& saludJugador) {
    std::ifstream archivoEntrada(archivo);
    if (archivoEntrada.is_open()) {
        archivoEntrada >> posicionX >> posicionY >> saludJugador;
        archivoEntrada.close();
        std::cout << "Estado del juego cargado desde " << archivo << std::endl;
        return true;
    } else {
        std::cerr << "Error al abrir el archivo para cargar el estado." << std::endl;
        return false;
    }
}
