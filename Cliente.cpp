#include <iostream>
#include <queue>
#include <stack>
#include "Cliente.h"
#include <string>
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
    int compraTotal = 0, idProducto, opcion, opcion2;

    string boleta = "\n------------- Boleta --------------" "\n----Tipo cliente: " 
                    + cliente->getTipoCliente() + "\n----Numero cliente: " + to_string(cliente->getNumeroAtencion())
                    + "\n------------- Compra -------------";

    cout<<"\nProductos del cliente numero "<< cliente->getNumeroAtencion() <<": "<<endl;

    do
    {
        aux->verificarIdProducto(idProducto, idProductos);
        bodega->get(idProducto)->setCantidadProducto(-1);
        producto = bodega->get(idProducto);
        if(producto->getCantidadProducto() == 0){cout<<"\nSin stock de producto...\n";}
        else
        {
            compraTotal += producto->getPrecioProducto();
            boleta += "\nProducto: " + producto->getProducto() + "| Precio: " + to_string(producto->getPrecioProducto());
        }

        do
        {
            cout<<"\n¿Se ingresara otro producto?"
                <<"\n1) Si"
                <<"\n2) No"
                <<"\nElija una de las opciones(Ejemplo: 1): ";
            cin>>opcion;
            if(opcion == 2)
            {
                boleta += "\nTotal a pagar: " + to_string(compraTotal) + "\n";
                break;
            }
            else if(opcion != 1){cout<<"\nLa opcion seleccionada es incorrecta...";}

        } while(opcion != 1);

    } while(opcion == 1);
    
    cout<<"\n¿Desea imprimir boleta?"
        <<"\n1) Si"
        <<"\n2) No"
        <<"\nElija una de las opciones(Ejemplo: 1): ";
    cin>>opcion2;
    if(opcion2 == 1){cout<<boleta<<endl;}
    else if(opcion2 == 2){cout<<"\nCliente atendido con exito....\n";}
}

string Cliente::getTipoCliente()
{
    return this->tipoCliente;
}

int Cliente::getNumeroAtencion()
{
    return this->numeroAtencion;
}