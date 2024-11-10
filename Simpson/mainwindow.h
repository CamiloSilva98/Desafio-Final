#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "item.h"
#include <QMainWindow>
#include <QGraphicsScene> // Paquete para control de scena
#include <QGraphicsView> // paquete para vistas.
#include <QTimer>
#include <QKeyEvent>


QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr); // Constructor
    ~MainWindow(); // destructor
//
protected:
    // Añadimos el manejo de teclas
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
 //
private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;   // La escena que se va a construir.
    void agregarObjeto(int x, int y, const QString &rutaImagen);
    void crearEscena();  // Método para configurar la escena y agregar las paredes

    //
    QGraphicsPixmapItem *bart;
    bool estaCorriendo = false;
    bool tieneObjeto = false;
    bool estaEmpujando = false;
    int velocidadBart = 5;
    QPixmap spriteNormal;
    QPixmap spriteCorriendo;
    QPixmap spriteEmpujando;
    QPixmap spriteLanzando;
    QList<QGraphicsPixmapItem*> cervezas; // Lista de cervezas en la escena

    // Funciones para Bart
    void inicializarBart();
    void moverBart(int dx, int dy);
    void lanzarCerveza();
    bool checkCollision(int newX, int newY);
    //

};
#endif // MAINWINDOW_H
