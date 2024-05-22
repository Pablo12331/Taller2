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

    ordenarClientesPreferenciales(terceraEdad);
    ordenarClientesPreferenciales(discapacitados);
    ordenarClientesPreferenciales(embarazadas);

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

void Cliente::ordenarClientesPreferenciales(queue<Cliente*> &clientes)
{
    stack<Cliente*> pilaAux1, pilaAux2;
    
    Cliente* aux;
    
    if(clientes.empty()){return;}

    while(!clientes.empty())
    {
        pilaAux1.push(clientes.front());
        clientes.pop();
    }

    while(!pilaAux1.empty())
    {
        aux = pilaAux1.top();
        pilaAux1.pop();

        if(pilaAux2.empty())
        {
            pilaAux2.push(aux);
        }
        else if(pilaAux2.top()->getNumeroAtencion() > aux->getNumeroAtencion())
        {
            pilaAux2.push(aux);
        }
        else if(pilaAux2.top()->getNumeroAtencion() < aux->getNumeroAtencion())
        {
            while(!pilaAux2.empty() && aux->getNumeroAtencion() > pilaAux2.top()->getNumeroAtencion())
            {
                pilaAux1.push(pilaAux2.top());
                pilaAux2.pop();
            }
            pilaAux2.push(aux);
        }
    }
    while(!pilaAux2.empty())
    {
        clientes.push(pilaAux2.top());
        pilaAux2.pop();
    }
    aux = nullptr;
    delete(aux);    
}

void Cliente::atenderCliente(queue<Cliente*>& clientes, queue<Cliente*>& clientesPreferenciales)
{
    if(!clientesPreferenciales.empty())
    {
        clientesPreferenciales.front();
        clientesPreferenciales.pop();
    }
    else if(!clientes.empty())
    {

    }
}

string Cliente::getTipoCliente()
{
    return this->tipoCliente;
}

int Cliente::getNumeroAtencion()
{
    return this->numeroAtencion;
}