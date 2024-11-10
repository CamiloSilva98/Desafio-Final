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
private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;   // La escena que se va a construir.
    void agregarObjeto(int x, int y, const QString &rutaImagen);
    void crearEscena();  // Método para configurar la escena y agregar las paredes
};
#endif // MAINWINDOW_H
