#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <string>
const int N = 5;
using namespace std;

//Problema 2
void generarLetras(char *arreglo, int n);
void contarLetras(char *arreglo, int n, int *conteo);
void imprimirConteo(int *conteo);
void Problema2();

//Problema 4
int cadenaAEntero(const char *cadena);
void Problema4();

//Problema 6
void CambiarMayusculas(string &cadena);
void Problema6();

//Problema 8
void SepararLetraNumero(string &cadena);
void Problema8();

//Problema 10
int romanoAEntero(const string &romano);
int valorRomano(char c);
void Problema10();

//Problema 12
int** crearMatriz(int n);
void ingresarMatriz(int** matriz, int n);
void imprimirMatriz(int** matriz, int n);
bool esCuadradoMagico(int** matriz, int n);
void Problema12();

//Problema 14
void llenarMatriz(int matriz[N][N]);
void imprimirMatriz(int matriz[N][N]);
void rotar90(int origen[N][N], int destino[N][N]);
void Problema14();

//Problema 16
long long factorial(int n);
long long numeroDeCaminos(int n);
void Problema16();

//Problema 18
void Problema18();
#endif // FUNCIONES_H
