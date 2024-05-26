#include <iostream>
#include "Cliente.h"
#include "Producto.h"
#include "HashMap.h"
#include <queue>
#include <vector>
#include <fstream>

using namespace std;

// Este método muestra los datos de los productos en la bodega, incluyendo su ID, nombre y cantidad en stock.
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

// Este método actualiza los datos de la bodega en el archivo "Productos.txt", eliminando los productos que han sido atendidos.
void actualizarDatosBodega(HashMap* &bodega, vector<int> idProductos)
{
    Producto* aux;
    string actualizacionBodega = "";
    for(int id : idProductos)
    {
        if(bodega->getNumberOfElements() != 1){actualizacionBodega += bodega->get(id)->informacionProducto() + "\n";}
        else{actualizacionBodega += bodega->get(id)->informacionProducto();}
        bodega->erase(id);
    }
    aux->actualizarProductos(actualizacionBodega);
    aux = nullptr;
    delete(aux);
}

// Este método gestiona la atención de clientes en la farmacia, atendiendo primero a los clientes preferenciales y luego a los clientes regulares, mostrando los datos de la bodega antes de cada atención.
void atenderClientes(queue<Cliente*>& clientes, queue<Cliente*>& clientesPreferenciales, HashMap*& bodega, vector<int> idProductos)
{
    Cliente* aux;
    if(clientesPreferenciales.empty() && clientes.empty())
    {
        cout<<"No hay clientes en la fila."<<endl;
        return;
    }
    while(!clientes.empty() || !clientesPreferenciales.empty())
    {
        datosBodega(bodega, idProductos);
        if(!clientesPreferenciales.empty())
        {   
            aux->atencionCliente(clientesPreferenciales.front(), bodega, idProductos);
            clientesPreferenciales.pop();
        }
        else
        {
            aux->atencionCliente(clientes.front(), bodega, idProductos);
            clientes.pop();
        }
    }
}

// Este método permite reabastecer la bodega con nuevos productos, solicitando al usuario la cantidad de productos a reabastecer y el ID de los productos a reabastecer.
void reabastecerBodega(HashMap* &bodega, vector<int> idProductos)
{
    Producto* aux;
    int cantidadProductos, idProducto, stockSuma;
    datosBodega(bodega, idProductos);
    cout<<"\n¿Cuantos productos se van a reabastecer?(Ejemplo: 2): ";
    cin>>cantidadProductos;
    for(int i = 0; i < cantidadProductos; i++)
    {
        idProducto = aux->agregarProducto(idProductos, stockSuma);
        cout<<"\nStock agregado..."<<endl;
        bodega->get(idProducto)->setCantidadProducto(stockSuma);
    }
    cout<<"\nReabastecimiento completado..."<<endl;
}

// Este método muestra un menú al usuario y gestiona las opciones seleccionadas, llamando a las funciones correspondientes según la opción seleccionada.
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
        cout << "4. Salir\n";
        cout << "Ingrese una opción(Ejemplo: 1): ";
        cin >> opcion;
        cout<<endl;
        switch(opcion) {
            case 1:
                filas->entregaNumeroClientes(contPreferencial, contNoPreferencial, clientesPreferenciales, clientes);
                break;
            case 2:
                atenderClientes(clientes,clientesPreferenciales, bodega, idProductos);
                break;
            case 3:
                reabastecerBodega(bodega, idProductos);
                break;
            case 4:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opción no válida. Por favor, ingrese una opción válida.\n";
        }
    } while(opcion != 4);

    return 0;
}

// Este método carga los datos de los productos desde el archivo "Productos.txt" en la bodega y en el vector de IDs de productos.
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

// Este es el punto de entrada de la aplicación. Crea una instancia de la bodega, carga los datos de la bodega, muestra el menú al usuario y luego actualiza los datos de la bodega antes de finalizar.
void farmacia()
{
    vector<int> idProductos;
    HashMap* bodega = new HashMap();
    cargarDatosBodega(bodega, idProductos);
    menu(bodega, idProductos);
    actualizarDatosBodega(bodega,idProductos);
}

// La función principal del programa, que llama a la función farmacia() para ejecutar la aplicación de la farmacia.
int main()
{
    farmacia();
}




