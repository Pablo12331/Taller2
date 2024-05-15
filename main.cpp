#include <iostream>
#include "Cliente.h"
#include "Producto.h"

using namespace std;

int main()
{

}

int menu()
{
    int opcion;

    do {
        cout << "\n--- Menú ---\n";
        cout << "1. Entregar número de cliente\n";
        cout << "2. Llamar al siguiente cliente\n";
        cout << "3. Ingresar cliente a cola\n";
        cout << "4. Agregar productos a bodega\n";
        cout << "5. Generar boleta de venta\n";
        cout << "6. Salir\n";
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                // Método para entregar número de cliente
                break;
            case 2:
                // Método para llamar al siguiente cliente
                break;
            case 3:
                // Método para ingresar cliente a cola
                break;
            case 4:
                // Método para agregar productos a bodega
                break;
            case 5:
                // Método para generar boleta de venta
                break;
            case 6:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opción no válida. Por favor, ingrese una opción válida.\n";
        }
    } while(opcion != 6);

    return 0;
}