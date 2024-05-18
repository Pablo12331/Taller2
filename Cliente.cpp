#include <iostream>
#include <queue>
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
}

void Cliente::ordenarClientesPreferenciales(queue<Cliente> clientes)
{
    queue<Cliente*> mayores, menores;

    Cliente* aux;

    while(clientes.empty())
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