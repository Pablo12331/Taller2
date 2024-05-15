#pragma once 
#include <iostream>
#include <queue>
using namespace std;
class Cliente
{
    private:
        string tipoCliente, datoDiferenciador, numeroAtencion;
        queue<Cliente> clientes;
        queue<Cliente> clientesPreferenciales;
        
    public:
        Cliente(string, string, string);
        Cliente* registroClientes(string);
        
};