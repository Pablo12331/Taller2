#pragma once 
#include <iostream>
#include <queue>

using namespace std;

class Cliente
{
    private:
        string tipoCliente;
        int numeroAtencion;
        queue<Cliente*> clientes;
        queue<Cliente*> clientesPreferenciales;
        queue<int> listaCompra;

    public:
        Cliente(string, int);
        ~Cliente();
        void registroClientes(int&, int&);
        Cliente* nuevoClientePreferencial(int&);
        void separarClientesPreferenciales(queue<Cliente*>);
        void ordenarClientesPreferenciales(queue<Cliente*>&);
        int getNumeroAtencion();
        string getTipoCliente();
        void rellenarListaCompras();
        queue<Cliente*> getClientes();
        queue<Cliente*> getClientesPreferenciales();
};