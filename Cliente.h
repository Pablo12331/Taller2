#pragma once 
#include <iostream>
#include <queue>

using namespace std;

class Cliente
{
    private:
        string tipoCliente;
        int numeroAtencion;
        queue<Cliente> clientes;
        queue<Cliente> clientesPreferenciales;
        queue<int> listaCompra;

    public:
        Cliente(string, int);
        Cliente* registroClientes(string);
        void ordenarClientes(queue<Cliente>);
        void ordenarClientesPreferenciales(queue<Cliente>);
        int getNumeroAtencion();
        string getTipoCliente();
        void rellenarListaCompras();
};