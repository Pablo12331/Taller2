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

void Cliente::registroClientes(int& contPreferencial, int& contNoPreferencial)
{
    int opcion;

    do
    {
        cout<<"\n|---Tipo Cliente---|\n"
            <<"1) Preferencial\n"
            <<"2) No Preferencial\n"
            <<"\nElija una de las opciones(Ejemplo: 1): ";
        cin>>opcion;

        switch (opcion)
        {
            case 1:
                clientesPreferenciales.push(nuevoClientePreferencial(contPreferencial));
                break;
            case 2:
                contNoPreferencial++;
                Cliente* nuevoCliente = new Cliente("No Preferencial",contNoPreferencial);
                clientes.push(nuevoCliente);
                break;
            default:
                cout<<"\nLa opcion seleccionada es incorrecta, coloque una de las mostradas en pantalla."<<endl;
                break;
        }

    }
    while(opcion != 1 && opcion != 2);
}

Cliente* Cliente::nuevoClientePreferencial(int& contPreferencial)
{
    int opcion;
    contPreferencial++;
    do
    {
        cout<<"\n|---Cliente preferencial---|\n"
            <<"1) Tercera edad\n"
            <<"2) Discapacitado\n"
            <<"3) Embarazada\n"
            <<"\nElija una de las opciones(Ejemplo: 1): ";
        cin>>opcion;
        switch (opcion)
        {
            case 1:
                Cliente* nuevoCliente = new Cliente("Tercera edad",contPreferencial);
                return nuevoCliente;
                break;
            case 2:
                Cliente* nuevoCliente = new Cliente("Discapacitado",contPreferencial);
                return nuevoCliente;
                break;
            case 3:
                Cliente* nuevoCliente = new Cliente("Embarazada",contPreferencial);
                return nuevoCliente;
                break;
            default:
                cout<<"\nLa opcion seleccionada es incorrecta, coloque una de las mostradas en pantalla."<<endl;
                break;
        }        
    }   
    while (opcion < 1 || opcion > 3);
}

void Cliente::separarClientesPreferenciales(queue<Cliente*> clientes)
{
    queue<Cliente*> terceraEdad, discapacitados, embarazadas;
    
    while(!clientes.empty())
    {
        if(clientes.front()->getTipoCliente() == "Tercera edad")
        {
            terceraEdad.push(clientes.front());
            clientes.pop();
        }
        else if(clientes.front()->getTipoCliente() == "Discapacitado")
        {
            discapacitados.push(clientes.front());
            clientes.pop();
        }
        else
        {
            embarazadas.push(clientes.front());
            clientes.pop();
        }
    }

    ordenarClientesPreferenciales(terceraEdad);
    ordenarClientesPreferenciales(discapacitados);
    ordenarClientesPreferenciales(embarazadas);

    while(!terceraEdad.empty())
    {
        clientes.push(terceraEdad.front());
        terceraEdad.pop();
    }
    while(!discapacitados.empty())
    {
        clientes.push(discapacitados.front());
        discapacitados.pop();
    }
    while(!embarazadas.empty())
    {
        clientes.push(embarazadas.front());
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

string Cliente::getTipoCliente()
{
    return this->tipoCliente;
}

int Cliente::getNumeroAtencion()
{
    return this->numeroAtencion;
}
queue<Cliente*> Cliente::getClientes()
{
    return this->clientes;
}
queue<Cliente*> Cliente::getClientesPreferenciales()
{
    return this->clientesPreferenciales;
}