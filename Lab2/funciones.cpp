#include "funciones.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
//#include <string>
using namespace std;

void generarLetras(char *arreglo, int n)
{
    srand(time(0));
    for(int i = 0; i < n; i++)
    {
        *(arreglo + i) = 'A' + rand() % 26;
    }
}
void contarLetras(char *arreglo, int n, int *conteo)
{
    for(int i = 0; i < 26; i++) *(conteo + i) = 0;
    for(int i = 0; i < n; i++)
    {
        char letra = *(arreglo + i);
        if(letra >= 'A' && letra <= 'Z')
        {
            (*(conteo + (letra - 'A')))++;
        }
    }
}
void imprimirConteo(int *conteo)
{
    for(int i = 0; i < 26; i++)
    {
        cout << char('A' + i) << ": " << *(conteo + i) << endl;
    }
}
void Problema2()
{
    const int N = 200;
    char arreglo[N];
    int conteo[26];
    generarLetras(arreglo, N);
    cout << "Arreglo generado: ";
    for(int i = 0; i < N; i++) cout << arreglo[i];
    cout << endl;
    contarLetras(arreglo, N, conteo);
    imprimirConteo(conteo);
}
int cadenaAEntero(const char *cadena)
{
    int num = 0;
    while(*cadena)
    {
        num = num * 10 + (*cadena - '0');
        cadena++;
    }
    return num;
}
void Problema4()
{
    char cadena[20];
    cout << "Ingrese un numero en cadena: ";
    cin >> cadena;
    int num = cadenaAEntero(cadena);
    cout << "La cadena ingresada fue: " << cadena << endl;
    cout << "Convertido a entero: " << num << endl;
}
void CambiarMayusculas(string &cadena)
{
    for(size_t i = 0; i < cadena.length(); i++)
    {
        if(cadena[i] >= 'a' && cadena[i] <= 'z')
        {
            cadena[i] = cadena[i] - 32;  // pasa a mayúscula
        }
    }
}
void Problema6()
{
    cin.ignore();
    string cadena;
    cout << "Ingrese una cadena: ";
    getline(cin, cadena);
    cout << "Original: " << cadena << endl;
    CambiarMayusculas(cadena);
    cout << "En mayuscula: " << cadena << endl;
}
void SepararLetraNumero(string &cadena)
{
    string num;
    string text;
    for(size_t i = 0; i < cadena.length(); i++)
    {
        if((cadena[i] >= 'a' && cadena[i] <= 'z') || (cadena[i] >= 'A' && cadena[i] <= 'Z'))
        {
            text += cadena[i];
        }
        else
        {
            num += cadena[i];
        }
    }
    cout << "Texto: " << text << endl;
    cout << "Numeros: " << num <<endl;
}
void Problema8()
{
    cin.ignore();
    string cadena;
    cout << "Ingrese una cadena: ";
    getline(cin, cadena);
    cout << "Original: " << cadena << endl;
    SepararLetraNumero(cadena);
}
int romanoAEntero(const string &romano)
{
    int total = 0;
    for (size_t i = 0; i < romano.length(); i++)
    {
        int actual = valorRomano(romano[i]);
        int siguiente = (i + 1 < romano.length()) ? valorRomano(romano[i + 1]) : 0;

        if (actual < siguiente)
        {
            total -= actual;  // se resta
        }
        else
        {
            total += actual;  // se suma
        }
    }
    return total;
}
int valorRomano(char c)
{
    switch (c)
    {
    case 'M': return 1000;
    case 'D': return 500;
    case 'C': return 100;
    case 'L': return 50;
    case 'X': return 10;
    case 'V': return 5;
    case 'I': return 1;
    default: return 0;
    }
}
void Problema10()
{
    string romano;
    cout << "Ingrese un numero romano en mayusculas: ";
    cin >> romano;
    int resultado = romanoAEntero(romano);
    cout << "El numero ingresado fue: " << romano << endl;
    cout << "Que corresponde a: " << resultado << endl;
}
int** crearMatriz(int n)
{
    int** matriz = new int*[n];
    for (int i = 0; i < n; i++)
    {
        matriz[i] = new int[n];
    }
    return matriz;
}
void ingresarMatriz(int** matriz, int n)
{
    cout << "Ingrese los valores de la matriz:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matriz[i][j];
        }
    }
}
void imprimirMatriz(int** matriz, int n)
{
    cout << "Matriz ingresada:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}
bool esCuadradoMagico(int** matriz, int n)
{
    int constante = 0;
    for (int j = 0; j < n; j++)
    {
        constante += matriz[0][j];
    }

    // Verificar filas
    for (int i = 0; i < n; i++)
    {
        int sumaFila = 0;
        for (int j = 0; j < n; j++)
        {
            sumaFila += matriz[i][j];
        }
        if (sumaFila != constante) return false;
    }

    // Verificar columnas
    for (int j = 0; j < n; j++)
    {
        int sumaCol = 0;
        for (int i = 0; i < n; i++)
        {
            sumaCol += matriz[i][j];
        }
        if (sumaCol != constante) return false;
    }

    // Verificar diagonales
    int sumaDiag1 = 0, sumaDiag2 = 0;
    for (int i = 0; i < n; i++) {
        sumaDiag1 += matriz[i][i];
        sumaDiag2 += matriz[i][n - 1 - i];
    }
    if (sumaDiag1 != constante || sumaDiag2 != constante) return false;

    return true;
}
void Problema12()
{
    int n;
    cout << "Ingrese el dimension de la matriz cuadrada: ";
    cin >> n;
    int** matriz = crearMatriz(n);
    ingresarMatriz(matriz, n);
    imprimirMatriz(matriz, n);

    if (esCuadradoMagico(matriz, n))
    {
        cout << "La matriz es un cuadrado magico." << endl;
    }
    else
    {
        cout << "La matriz NO es un cuadrado magico." << endl;
    }

    // Liberar memoria
    for (int i = 0; i < n; i++)
    {
        delete[] matriz[i];
    }
    delete[] matriz;
}
void llenarMatriz(int matriz[N][N])
{
    int valor = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matriz[i][j] = valor++;
        }
    }
}
void imprimirMatriz(int matriz[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
}
void rotar90(int origen[N][N], int destino[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            destino[j][N - 1 - i] = origen[i][j];
        }
    }
}
void Problema14()
{
    int matriz[N][N];
    int rotada90[N][N], rotada180[N][N], rotada270[N][N];

    llenarMatriz(matriz);
    cout << "Matriz original:" << endl;
    imprimirMatriz(matriz);

    rotar90(matriz, rotada90);
    cout << "\nMatriz rotada 90 grados:" << endl;
    imprimirMatriz(rotada90);

    rotar90(rotada90, rotada180);
    cout << "\nMatriz rotada 180 grados:" << endl;
    imprimirMatriz(rotada180);

    rotar90(rotada180, rotada270);
    cout << "\nMatriz rotada 270 grados:" << endl;
    imprimirMatriz(rotada270);
}
long long factorial(int n)
{
    long long f = 1;
    for (int i = 2; i <= n; i++) f *= i;
    return f;
}
long long numeroDeCaminos(int n)
{
    return factorial(2*n) / (factorial(n) * factorial(n));
}
void Problema16() {
    int n;
    cout << "Ingrese el valor de n: ";
    cin >> n;

    long long caminos = numeroDeCaminos(n);

    cout << "Para una malla de " << n << "x" << n << " puntos hay "
         << caminos << " caminos." << endl;
}
