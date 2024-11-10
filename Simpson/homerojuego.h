#include "HomeroJuego.h"
#include <cmath>

HomeroJuego::HomeroJuego(QObject* parent)
    : QObject(parent),
    DURACION_EFECTO_DONA(5000),
    DURACION_EFECTO_CERVEZA(8000),
    VELOCIDAD_PERSECUCION(5),
    VELOCIDAD_TRANQUILO(0)
{
    estado_actual = PERSIGUIENDO;
    velocidad = VELOCIDAD_PERSECUCION;
    posicion = QPoint(0, 0);

    // Inicializar temporizadores
    timerEfectoDona = new QTimer(this);
    timerEfectoCerveza = new QTimer(this);

    connect(timerEfectoDona, &QTimer::timeout, this, &HomeroJuego::terminarEfectoDona);
    connect(timerEfectoCerveza, &QTimer::timeout, this, &HomeroJuego::terminarEfectoCerveza);
}

HomeroJuego::~HomeroJuego() {
    delete timerEfectoDona;
    delete timerEfectoCerveza;
}

QPoint HomeroJuego::getPosicion() const {
    return posicion;
}

HomeroJuego::Estado HomeroJuego::getEstado() const {
    return estado_actual;
}

int HomeroJuego::getVelocidad() const {
    return velocidad;
}

void HomeroJuego::mover(const QPoint& objetivo) {
    if (estado_actual == PERSIGUIENDO) {
        // Cálculo de la dirección hacia el objetivo
        int dx = objetivo.x() - posicion.x();
        int dy = objetivo.y() - posicion.y();

        // Normalizar y aplicar velocidad
        double distancia = sqrt(dx*dx + dy*dy);
        if (distancia > 0) {
            posicion.setX(posicion.x() + (dx/distancia) * velocidad);
            posicion.setY(posicion.y() + (dy/distancia) * velocidad);
        }

        emit posicionActualizada(posicion);
    }
}

void HomeroJuego::recibirDona() {
    if (estado_actual == PERSIGUIENDO) {
        estado_actual = TRANQUILO_DONA;
        velocidad = VELOCIDAD_TRANQUILO;
        emit cambioEstado(estado_actual);

        // Detener timer anterior si existe
        timerEfectoDona->stop();
        // Iniciar nuevo timer
        timerEfectoDona->start(DURACION_EFECTO_DONA);

        emit mensajeEstado("¡Mmm... dona! *Se detiene temporalmente*");
    }
}

void HomeroJuego::recibirCerveza() {
    if (estado_actual == PERSIGUIENDO) {
        estado_actual = TRANQUILO_CERVEZA;
        velocidad = VELOCIDAD_TRANQUILO;
        emit cambioEstado(estado_actual);

        // Detener timer anterior si existe
        timerEfectoCerveza->stop();
        // Iniciar nuevo timer
        timerEfectoCerveza->start(DURACION_EFECTO_CERVEZA);

        emit mensajeEstado("¡Woo hoo! ¡Cerveza! *Se detiene temporalmente*");
    }
}

void HomeroJuego::terminarEfectoDona() {
    if (estado_actual == TRANQUILO_DONA) {
        estado_actual = PERSIGUIENDO;
        velocidad = VELOCIDAD_PERSECUCION;
        emit cambioEstado(estado_actual);
        emit mensajeEstado("¡Se acabó la dona! ¡Los atraparé pequeños demonioooos!");
    }
}

void HomeroJuego::terminarEfectoCerveza() {
    if (estado_actual == TRANQUILO_CERVEZA) {
        estado_actual = PERSIGUIENDO;
        velocidad = VELOCIDAD_PERSECUCION;
        emit cambioEstado(estado_actual);
        emit mensajeEstado("¡Se acabó la cerveza! ¡Vuelvan aquí!");
    }
}
