#include "funciones.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
//#include <string>
using namespace std;

// Genera letras mayúsculas aleatorias
void generarLetras(char *arreglo, int n)
{
    srand(time(0));
    for(int i = 0; i < n; i++)
    {
        *(arreglo + i) = 'A' + rand() % 26;
    }
}
// Cuenta las repeticiones de cada letra
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
// Imprime el conteo de letras
void imprimirConteo(int *conteo)
{
    for(int i = 0; i < 26; i++)
    {
        cout << char('A' + i) << ": " << *(conteo + i) << endl;
    }
}
// Ejecuta el problema 2
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
