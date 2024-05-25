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

void datosBodega(HashMap* &bodega, vector<int> idProductos)
{
    cout<<"Lista de productos en bodega: "<<endl;
    Producto* aux;
    for(int id : idProductos)
    {
        aux = bodega->get(id);
        cout<<"ID: "<<id<<"| Nombre: "<< aux->getProducto()<<"| Stock: " <<aux->getCantidadProducto()<<endl; 
    }
    return;
}

void imprimirBoleta(string boleta)
{
    cout<<"--------------Boleta--------------"<<endl;
    cout<<""<<endl;


}

void reabastecerBodega(HashMap* &bodega, vector<int> idProductos)
{
    Producto* aux;
    int cantidadProductos, idProducto, stockSuma = -1;
    datosBodega(bodega, idProductos);
    cout<<"\n¿Cuantos productos se van a reabastecer?(Ejemplo: 2): ";
    cin>>cantidadProductos;
    for(int i = 0; i < cantidadProductos; i++)
    {
        idProducto = aux->agregarProducto(idProductos, stockSuma);
        cout<<"\nStock agregado..."<<endl;
        bodega->get(idProducto)->setCantidadProducto(stockSuma);
    }
    cout<<"\nReabastecimiento completo..."<<endl;
}

int menu(HashMap*& bodega, vector<int> idProductos)
{
    //transformar los vectores en filas
    Cliente* filas;
    queue<Cliente*> clientesPreferenciales;
    queue<Cliente*> clientes;
    int opcion, contNoPreferencial = 0, contPreferencial = 0;
    string boletaActiva;
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
                filas->entregaNumeroClientes(contPreferencial, contNoPreferencial, clientesPreferenciales, clientes);
                break;
            case 2:
                boletaActiva = filas->atenderCliente(clientes,clientesPreferenciales);
                break;
            case 3:
                reabastecerBodega(bodega, idProductos);
                break;
            case 4:
                imprimirBoleta(boletaActiva);
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
    while(!clientes.empty())
    {
        cout<<clientes.front()->getNumeroAtencion()<<endl;
        clientes.pop();
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




