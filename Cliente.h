#pragma once 
#include <iostream>
#include <queue>

using namespace std;

class Cliente
{
    private:
        string tipoCliente;
        int numeroAtencion;
        queue<int> listaCompra;

    public:
        Cliente(string, int);
        ~Cliente();
        void entregaNumeroClientes(int&, int&,queue<Cliente*>&,queue<Cliente*>&);
        void registroClientes(int&, int&,queue<Cliente*>&,queue<Cliente*>&);
        Cliente* nuevoClientePreferencial(int&);
        void separarClientesPreferenciales(queue<Cliente*>&);
        void ordenarClientesPreferenciales(queue<Cliente*>&);
        int getNumeroAtencion();
        string getTipoCliente();
        void rellenarListaCompras();
        string atenderCliente(queue<Cliente*>&, queue<Cliente*>&);
        void atencionClientePreferencial(Cliente* cliente);
        void atencionClienteNoPreferencial(Cliente* cliente);
        queue<int> getListaCompra();
};