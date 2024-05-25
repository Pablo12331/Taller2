#pragma once 
#include <iostream>
#include <queue>
#include <vector>
#include "HashMap.h"
#include "Producto.h"

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
        string atenderClientes(queue<Cliente*>&, queue<Cliente*>&, HashMap*&, vector<int>);
        void atencionCliente(Cliente*, HashMap*&, vector<int>);
        queue<int> getListaCompra();
};