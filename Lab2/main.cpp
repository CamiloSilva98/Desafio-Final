#include <iostream>
#include "funciones.h"
using namespace std;

int main()
{
    int opcion;

    do
    {
        cout << "\n--- MENU DE PROBLEMAS ---\n";
        cout << "1. Problema 2\n";
        cout << "2. Problema 4\n";
        cout << "3. Problema 6\n";
        cout << "4. Problema 8\n";
        cout << "5. Problema 10\n";
        cout << "6. Problema 12\n";
        cout << "7. Problema 14\n";
        cout << "8. Problema 16\n";
        cout << "9. Problema 18\n";
        cout << "0. Salir\n";
        cout << "Seleccione un problema: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1: Problema2(); break;
        case 2: Problema4(); break;
        case 3: Problema6(); break;
        case 4: Problema8(); break;
        case 5: Problema10(); break;
        //case 6: Problema12(); break;
        //case 7: Problema14(); break;
        //case 8: Problema16(); break;
        //case 9: Problema18(); break;
        case 0: cout << "Saliendo...\n"; break;
        default: cout << "Opcion invalida\n";
        }
    } while (opcion != 0);

    return 0;
}

