#include <iostream>
#include "Cliente.h"
#include "Producto.h"
#include "HashMap.h"
#include <queue>
#include <vector>
#include <fstream>

using namespace std;

// int atenderCliente(Cliente* aux)
// {
//     if(aux->getClientes().empty() && aux->getClientesPreferenciales().empty())
//     {
//         cout<<"No hay clientes en la fila."<<endl;
//     }
//     else if(!aux->getClientes().empty())
//     {
//         aux->atenderCliente(aux->getClientes());
//     }

//     //condicional que pregunta si hay elementos en alguna lista, si no lo hay, tira un mensaje diciendo que no hay personas en la cola y se termina el método.
//     //condicional que pregunta si hay elementos en preferencial, si los hay: aux->ordenarClientesPreferenciales(aux->clientesPreferenciales). 
//     //otro condicional que no depende del anterior, que pregunta si hay clientes en estándar, si los hay: aux->ordenarClientes(aux->clientes).
//     return 0;
// }

int menu(HashMap*& bodega, vector<int> idProductos)
{
    Cliente* filas;
    Producto* aux;
    queue<Cliente*> clientesPreferenciales;
    queue<Cliente*> clientes;
    int contNoPreferencial = 0;
    int contPreferencial = 0;
    int opcion;

    do {
        cout << "\n|--- Menú ---|\n";
        cout << "1. Entregar número de cliente\n";
        cout << "2. Atender cliente\n";
        cout << "3. Reabastecer bodega\n";
        cout << "4. Generar boleta de venta\n";
        cout << "5. Salir\n";
        cout << "Ingrese una opción(Ejemplo: 1): ";
        cin >> opcion;
        cout<<endl;
        switch(opcion) {
            case 1:
                int cantidadPersonas;
                cout<<"¿Cuantas personas hay?(Ejemplo: 5): ";
                cin>>cantidadPersonas;
                for (int i = 0; i < cantidadPersonas; i++)
                {
                    filas->registroClientes(contPreferencial, contNoPreferencial, clientesPreferenciales, clientes);
                }
                filas->separarClientesPreferenciales(clientesPreferenciales);
                break;
            case 2:
                //atenderCliente(filas);
                break;
            case 3:
                aux->agregarProducto(bodega, idProductos);
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

    while(!clientesPreferenciales.empty())
    {
        cout<<clientesPreferenciales.front()->getNumeroAtencion()<<endl;
        clientesPreferenciales.pop();
    }

    return 0;
}

void cargarDatosBodega(HashMap* &bodega, vector<int> &idProductos)
{
    Producto* aux;
    
    string linea;

    ifstream datosProductos("Productos.txt");

    if(datosProductos.fail()){cout<<"ERROR! no se pudo leer el archivo de productos."; exit(1);}

    while(getline(datosProductos, linea))
    {
        Producto* producto = aux->ingresarProductos(linea);
        int id = producto->getIdProducto();
        idProductos.push_back(id);
        bodega->insert(id, producto);
    }
    datosProductos.close();
}

void farmacia()
{
    vector<int> idProductos;
    HashMap* bodega = new HashMap();
    cargarDatosBodega(bodega, idProductos);
    menu(bodega, idProductos);
}

int main()
{
    farmacia();
}



