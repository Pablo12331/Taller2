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

void Cliente::atencionClientePreferencial(Cliente* cliente)
{

}

void Cliente::atencionClienteNoPreferencial(Cliente* cliente)
{

}

string Cliente::atenderCliente(queue<Cliente*>& clientes, queue<Cliente*>& clientesPreferenciales)
{
    if(clientesPreferenciales.empty() && clientes.empty())
    {
        cout<<"No hay clientes en la fila."<<endl;
        return nullptr;
    }
    if(!clientesPreferenciales.empty())
    {
        Cliente* cliente = clientesPreferenciales.front();
        clientesPreferenciales.pop();
        string boleta;
        //Proceso aleatorio para determinar la compra (el cual se guarda como string en "boleta"), que posteriormente se mostrará en la boleta del punto 4.
        return boleta;
    }
    if(!clientes.empty())
    {
        Cliente* cliente = clientes.front();
        clientes.pop();
        string boleta;
        //Proceso aleatorio para determinar la compra (el cual se guarda como string en "boleta"), que posteriormente se mostrará en la boleta del punto 4.
        return boleta;
    }
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