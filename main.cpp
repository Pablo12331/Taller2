#include <iostream>
#include "Cliente.h"
#include "Producto.h"
#include "HashMap.h"
#include <fstream>

using namespace std;

// int ingresarClientes(Cliente* aux,int* contComun,int* contPref)
// {
//     int cant;
//     cout<<"Ingrese la cantidad de clientes que ingresaron: "<<endl;
//     cin>>cant;
//     int opcion;

//     for(int i = 0;i<cant ;i++)
//     {

//         while (true)
//         {
//             cout<<"Que tipo de cliente es?:\n"<<endl
//                 <<" 1)Estándar"<<endl
//                 <<" 2)Preferencial"<<endl;
//             cin>>opcion;

//             if(opcion == 1)
//             {
//                 contComun++;
//                 Cliente* nuevoCliente = new Cliente("Estándar",*contComun);
//                 //aquí se añade el nuevo cliente a la lista de comunes en el auxiliar (porfavor hacelo pablo q todavía no sé hashmap dou)
//                 break;
//             }
//             if(opcion == 2)
//             {
//                 contPref++;
//                 Cliente* nuevoCliente = new Cliente("Preferencial",*contPref);
//                 //aquí se añade el nuevo cliente a la lista de preferenciales en el auxiliar (porfavor hacelo pablo q todavía no sé hashmap dou)
//                 break;
//             }
//             cout<<"Respuesta errónea, intentelo de nuevo:"<<endl;
//         }
//     }
//     return 0;
// }

int atenderCliente(Cliente* aux)
{
    //condicional que pregunta si hay elementos en alguna lista, si no lo hay, tira un mensaje diciendo que no hay personas en la cola y se termina el método.
    //condicional que pregunta si hay elementos en preferencial, si los hay: aux->ordenarClientesPreferenciales(aux->clientesPreferenciales). 
    //otro condicional que no depende del anterior, que pregunta si hay clientes en estándar, si los hay: aux->ordenarClientes(aux->clientes).
    return 0;
}

int menu()
{
    Cliente* filas;
    int contNoPreferencial = 0;
    int contPreferencial = 0;
    int opcion;

    do {
        cout << "\n|--- Menú ---|\n";
        cout << "1. Entregar número de cliente\n";
        cout << "2. Atender cliente\n";
        cout << "3. Agregar productos a bodega\n";
        cout << "4. Generar boleta de venta\n";
        cout << "5. Salir\n";
        cout << "Ingrese una opción(Ejemplo: 1): ";
        cin >> opcion;
        cout<<endl;
        switch(opcion) {
            case 1:
                filas->registroClientes(contPreferencial, contNoPreferencial);
                break;
            case 2:
                atenderCliente(filas);
                break;
            case 3:
                // Método para agregar productos a bodega
                break;
            case 4:
                // Método para generar boleta de venta
                break;
            case 5:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opción no válida. Por favor, ingrese una opción válida.\n";
        }
    } while(opcion != 5);

    return 0;
}

void cargarDatosBodega(HashMap* bodega)
{
    Producto* aux;
    
    string linea;

    ifstream datosProductos("Productos.txt");

    if(datosProductos.fail()){cout<<"ERROR! no se pudo leer el archivo de productos."; exit(1);}

    while(getline(datosProductos, linea))
    {
        Producto* producto = aux->ingresarProductos(linea);
        int id = producto->getIdProducto();
        bodega->insert(id, producto);
    }
    datosProductos.close();
}

void suma(int &a)
{
    a++;
}

void farmacia()
{
    int a = 1;
    suma(a);
    cout<<a<<endl; 
    HashMap* bodega = new HashMap();
    cargarDatosBodega(bodega);
    //menu();
}

int main()
{
    farmacia();
}



