#include <iostream>
#include <queue>
#include "Cliente.h"

Cliente::Cliente(string tipoCliente, int numeroAtencion)
{
    this ->tipoCliente = tipoCliente;
    this ->numeroAtencion = numeroAtencion;
} 

Cliente::~Cliente(){}

Cliente* Cliente::registroClientes(string datosCliente)
{
    
    
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