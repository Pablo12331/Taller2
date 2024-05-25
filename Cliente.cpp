#include <iostream>
#include <queue>
#include <stack>
#include "Cliente.h"

Cliente::Cliente(string tipoCliente, int numeroAtencion)
{
    this ->tipoCliente = tipoCliente;
    this ->numeroAtencion = numeroAtencion;
} 

Cliente::~Cliente(){}

void Cliente::entregaNumeroClientes(int& contPreferencial, int& contNoPreferencial, queue<Cliente*>& clientesPreferenciales, queue<Cliente*>& clientes)
{
    int cantidadPersonas;
    cout<<"¿Cuantas personas hay?(Ejemplo: 5): ";
    cin>>cantidadPersonas;
    for (int i = 0; i < cantidadPersonas; i++)
    {
        registroClientes(contPreferencial, contNoPreferencial, clientesPreferenciales, clientes);
        cout<<"\nNumero entregado...\n";
    }
    separarClientesPreferenciales(clientesPreferenciales);
}

void Cliente::registroClientes(int& contPreferencial, int& contNoPreferencial, queue<Cliente*>& clientesPreferenciales, queue<Cliente*>& clientes)
{
    int opcion;
    do
    {
        cout<<"\n|---Tipo Cliente---|\n"
            <<"1) Preferencial\n"
            <<"2) No Preferencial\n"
            <<"\nElija una de las opciones(Ejemplo: 1): ";
        cin>>opcion;

        if(opcion == 1)
        {
            clientesPreferenciales.push(nuevoClientePreferencial(contPreferencial));
        }
        else if(opcion == 2)
        {

            contNoPreferencial++;
            Cliente* nuevoCliente = new Cliente("No Preferencial",contNoPreferencial);
            clientes.push(nuevoCliente);
        } 
          
    }
    while(opcion != 1 && opcion != 2);
}

Cliente* Cliente::nuevoClientePreferencial(int& contPreferencial)
{
    int opcion;
    Cliente* nuevoCliente;
    contPreferencial++;
    do
    {
        cout<<"\n|---Cliente preferencial---|\n"
            <<"1) Tercera edad\n"
            <<"2) Discapacitado\n"
            <<"3) Embarazada\n"
            <<"\nElija una de las opciones(Ejemplo: 1): ";
        cin>>opcion;
        if(opcion == 1)
        {
            nuevoCliente = new Cliente("Tercera edad",contPreferencial);
        } 
        else if (opcion == 2)
        {
            nuevoCliente = new Cliente("Discapacitado",contPreferencial);
            return nuevoCliente;
        }
        else if (opcion == 3)
        {
            nuevoCliente = new Cliente("Embarazada",contPreferencial);
            return nuevoCliente;
        }
    }while (opcion < 1 || opcion > 3);
    return nuevoCliente;
}

void Cliente::separarClientesPreferenciales(queue<Cliente*>& clientesPreferenciales)
{
    queue<Cliente*> terceraEdad, discapacitados, embarazadas;
    
    while(!clientesPreferenciales.empty())
    {
        if(clientesPreferenciales.front()->getTipoCliente() == "Tercera edad")
        {
            terceraEdad.push(clientesPreferenciales.front());
            clientesPreferenciales.pop();
        }
        else if(clientesPreferenciales.front()->getTipoCliente() == "Discapacitado")
        {
            discapacitados.push(clientesPreferenciales.front());
            clientesPreferenciales.pop();
        }
        else
        {
            embarazadas.push(clientesPreferenciales.front());
            clientesPreferenciales.pop();
        }
    }

    while(!terceraEdad.empty())
    {
        clientesPreferenciales.push(terceraEdad.front());
        terceraEdad.pop();
    }
    while(!discapacitados.empty())
    {
        clientesPreferenciales.push(discapacitados.front());
        discapacitados.pop();
    }
    while(!embarazadas.empty())
    {
        clientesPreferenciales.push(embarazadas.front());
        embarazadas.pop();
    }
}

void Cliente::atencionCliente(Cliente* cliente, HashMap*& bodega, vector<int> idProductos)
{
    Producto* aux;
    Producto* producto;
    int compraTotal, idProducto;

    string boleta = "\n---------- Boleta ----------" "\n----Tipo cliente: " 
                    + cliente->getTipoCliente() + "\n----Numero cliente: " + to_string(cliente->getNumeroAtencion());

    cout<<"\nProductos compra del cliente numero "<< cliente->getNumeroAtencion() <<": "<<endl;

    idProducto = aux->verificarIdProducto(idProducto, idProductos);

    producto = bodega->get(idProducto);
    
    boleta += "\n---------- Compra ----------"  "\nProducto: " + producto->getProducto() + " " + to_string(producto->getPrecioProducto());

}

string Cliente::atenderClientes(queue<Cliente*>& clientes, queue<Cliente*>& clientesPreferenciales, HashMap*& bodega, vector<int> idProductos)
{
    string boleta;
    
    return "";
}

string Cliente::getTipoCliente()
{
    return this->tipoCliente;
}

int Cliente::getNumeroAtencion()
{
    return this->numeroAtencion;
}