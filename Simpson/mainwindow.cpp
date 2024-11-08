#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(1200, 600);

    scene = new QGraphicsScene(this);
    //crearEscena();

    scene->setSceneRect(0, 0, 1200, 600);

    QGraphicsView *view = new QGraphicsView(scene, this);
    view->setFixedSize(1205, 605);
    view->setBackgroundBrush(QBrush(QColor("black")));
    setCentralWidget(view);
}
void MainWindow::crearEscena()
{
    //scene->setSceneRect(0, 0, winX, winY);
    //
    //QPixmap wallTexture("muros.png");
    //QBrush wallBrush(wallTexture);
    //wallBrush.setStyle(Qt::TexturePattern);
    //
    //// Muros del borde
    //QGraphicsRectItem *topWall = new QGraphicsRectItem(0, 0, winX, wallSize);
    //topWall->setData(0, "pared");
    //topWall->setBrush(wallBrush);
    //scene->addItem(topWall);
    //
    //QGraphicsRectItem *bottomWall = new QGraphicsRectItem(0, winY - wallSize, winX, wallSize);
    //bottomWall->setData(0, "pared");
    //bottomWall->setBrush(wallBrush);
    //scene->addItem(bottomWall);
    //
    //QGraphicsRectItem *leftWall = new QGraphicsRectItem(0, 0, wallSize, winY);
    //leftWall->setData(0, "pared");
    //leftWall->setBrush(wallBrush);
    //scene->addItem(leftWall);
    //
    //QGraphicsRectItem *rightWall = new QGraphicsRectItem(winX - wallSize, 0, wallSize, winY);
    //rightWall->setData(0, "pared");
    //rightWall->setBrush(wallBrush);
    //scene->addItem(rightWall);

}

MainWindow::~MainWindow()
{
    delete ui;
}
