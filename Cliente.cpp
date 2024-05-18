#include <iostream>
#include <queue>
#include "Cliente.h"

Cliente::Cliente(string tipoCliente, int numeroAtencion)
{
    this ->tipoCliente = tipoCliente;
    this ->numeroAtencion = numeroAtencion;
} 

Cliente::~Cliente(){}

Cliente* Cliente::registroClientes()
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
                break;
            case 2:
                break;
            default:
                break;
        }

    }
    while(opcion != 1 && opcion != 2);
}

void Cliente::ordenarClientes(queue<Cliente> clientes)
{

}

void Cliente::ordenarClientesPreferenciales(queue<Cliente> clientes)
{

}

string Cliente::getTipoCliente()
{
    return this->tipoCliente;
}

int Cliente::getNumeroAtencion()
{
    return this->numeroAtencion;
}