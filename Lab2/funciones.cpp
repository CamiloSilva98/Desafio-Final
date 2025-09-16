#include "funciones.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

// Genera letras mayúsculas aleatorias
void generarLetras(char *arreglo, int n)
{
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        *(arreglo + i) = 'A' + rand() % 26;
    }
}
// Cuenta las repeticiones de cada letra
void contarLetras(char *arreglo, int n, int *conteo)
{
    for (int i = 0; i < 26; i++) *(conteo + i) = 0;
    for (int i = 0; i < n; i++)
    {
        char letra = *(arreglo + i);
        if (letra >= 'A' && letra <= 'Z')
        {
            (*(conteo + (letra - 'A')))++;
        }
    }
}
// Imprime el conteo de letras
void imprimirConteo(int *conteo)
{
    for (int i = 0; i < 26; i++)
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
    for (int i = 0; i < N; i++) cout << arreglo[i];
    cout << endl;
    contarLetras(arreglo, N, conteo);
    imprimirConteo(conteo);
}
int cadenaAEntero(const char *cadena)
{
    int num = 0;
    while (*cadena)
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
    for (size_t i = 0; i < cadena.length(); i++)
    {
        if (cadena[i] >= 'a' && cadena[i] <= 'z')
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

}
